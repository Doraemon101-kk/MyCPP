#include "file_reader.hpp"
#include "text_input.hpp"
#include "word_counts.hpp"

#include <charconv>
#include <cstddef>
#include <iostream>
#include <set>
#include <string>
#include <string_view>

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: text_analyzer K [--stop-words file] file [file ...]\n";
        return 1;
    }

    // argv[1] 是文字；string_view 只查看它，不复制或拥有文字。
    const std::string_view input_k(argv[1]);
    std::size_t k = 0;
    // 将 [开头, 末尾) 的字符解析为数字，并把结果写入 k。
    const auto parsed = std::from_chars(input_k.data(), input_k.data() + input_k.size(), k);
    // ec 非空表示解析出错；ptr 未到末尾表示还有未解析的字符（如 12abc）。
    if (parsed.ec != std::errc{} || parsed.ptr != input_k.data() + input_k.size())
    {
        std::cerr << "K must be a non-negative integer within range.\n";
        return 1;
    }

    // 没有停用词选项时，普通输入文件从 argv[2] 开始。
    int first_file = 2;
    std::set<std::string> stop_words;
    if (std::string_view(argv[first_file]) == "--stop-words")
    {
        // 需要依次提供选项、停用词文件和至少一个普通输入文件。
        if (argc < 5)
        {
            std::cerr << "Expected a stop-words file and at least one input file.\n";
            return 1;
        }
        std::string stop_content;
        if (!read_text_file(argv[3], stop_content))
        {
            std::cerr << "Cannot read stop-words file: " << argv[3] << '\n';
            return 1;
        }
        // 使用相同的分词和小写规则；set 会自动去除重复词。
        const auto stop_tokens = text::tokenize_ascii_lower(stop_content);
        stop_words.insert(stop_tokens.begin(), stop_tokens.end());
        first_file = 4; // 跳过选项及其文件路径，从 argv[4] 开始分析。
    }

    std::vector <std::string> words;
    std::size_t successful_files = 0;
    for (int i = first_file; i < argc; ++i)
    {
        const std::string file_path = argv[i];
        std::string content;
        if (!read_text_file(file_path, content))
        {
            std::cerr << "Cannot read file: " << file_path << '\n';
            continue;
        }

        ++successful_files;

        const auto file_words = text::tokenize_ascii_lower(content);
        words.insert(words.end(), file_words.begin(), file_words.end());
    }

    if (successful_files == 0)
    {
        std::cerr << "No files could be read.\n";
        return 1;
    }

    WordCounts counts = count_words(words);
    // 先过滤停用词，再排序取前 K 条，避免停用词占据报告位置。
    remove_stop_word(counts, stop_words);
    const WordCountsReport report = make_report(1, counts, k);
    
    for (const auto& entry : report)
    {
        std::cout << "Word: " << entry.first << '\n';
        std::cout << "Counts: " << entry.second << '\n';
    }
    return 0;
}
