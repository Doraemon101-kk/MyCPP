#include "word_counts.hpp"

#include <cassert>
#include <vector>

int main()
{
    const std::vector<std::string> words{"cat", "dog", "cat"};
    const auto original = words;
    const auto counts = count_words(words);

    assert(counts.size() == 2);
    assert(counts.at("cat") == 2);
    assert(counts.at("dog") == 1);
    assert(words == original);
    assert(count_words({}).empty());

    WordCounts filtered_counts{{"cat", 2}, {"dog", 1}};
    const std::set<std::string> stop_words{"cat", "cat", "missing"};
    remove_stop_word(filtered_counts, stop_words);
    assert(stop_words.size() == 2);
    assert(filtered_counts.count("cat") == 0);
    assert(filtered_counts.at("dog") == 1);

    remove_stop_word(filtered_counts, {"dog"});
    assert(filtered_counts.empty());
    remove_stop_word(filtered_counts, {"missing"});
    assert(filtered_counts.empty());

    const WordCounts report_input{{"cat", 2}, {"dog", 3}, {"ant", 2}, {"bird", 1}};
    const WordCounts report_original = report_input;
    const WordCountsReport expected{{"dog", 3}, {"ant", 2}, {"cat", 2}};
    assert(make_report(2, report_input, 10) == expected);
    assert(report_input == report_original);
    assert(make_report(1, {}, 5).empty());
    assert(make_report(4, report_input, 5).empty());
    assert(make_report(2, report_input, 0).empty());
    const WordCountsReport top_two{{"dog", 3}, {"ant", 2}};
    assert(make_report(2, report_input, 2) == top_two);
    assert(make_report(2, report_input, 3) == expected);
    assert(report_input == report_original);
}
