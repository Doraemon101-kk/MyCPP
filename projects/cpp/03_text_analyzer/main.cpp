#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

struct WordCount
{
    std::string word;
    std::size_t count;
};

// 9/30从已分词的小写词开始。后续再实现tokenize和文件读写。
std::map<std::string, std::size_t> count_words(
    const std::vector<std::string>& words,
    const std::set<std::string>& stop_words);

// 次数降序，同频按word字典序升序；K=0返回空。
std::vector<WordCount> top_words(
    const std::map<std::string, std::size_t>& counts, std::size_t k);

// 10/5：词是连续ASCII字母，转小写；其他字节作分隔。
std::vector<std::string> tokenize(const std::string& text);

int main()
{
    const std::vector<std::string> words{
        "red", "red", "blue", "and", "blue", "green",
    };
    const std::set<std::string> stop_words{"and"};

    // TODO 1（9/30）: 统计、查询，合并第二批词；查询不存在词不插入新项。
    // TODO 2（10/4）: 停用词、最小次数、排序报告；选一段循环用算法改写。
    // TODO 3（10/5）: 原始文本分词，接到已有统计流程。
    // TODO 4（10/6）: 从参数给定文件读取，输出报告；区分空文件和失败。
    // TODO 5（10/7）: 将main改为接收argc/argv，解析K并处理非法参数。
    // TODO 6（10/10）: 移植自己的实现到split_template，添加断言测试。
    // TODO 7（10/11）: 完整v1；按小写统计，显示第一次出现的原拼写。
    // TODO 8（10/12）: 对比04_labs中的堆TopK与全排序，不急于换实现。
    // TODO 9（10/17）: 多文件摘要、总计、长度筛选、失败文件列表。
    // TODO 10（10/18）: 从干净目录构建；写真实运行方法，回归全部样例。

    std::cout << "Text analyzer scaffold: " << words.size()
              << " words, " << stop_words.size()
              << " stop word; analysis is not implemented.\n";
    return 0;
}
