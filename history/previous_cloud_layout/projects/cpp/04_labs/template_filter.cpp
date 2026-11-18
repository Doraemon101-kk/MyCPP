#include "filter_template.hpp"
#include <iostream>
#include <string>
#include <vector>

struct WordCount
{
    std::string word;
    int count;
};

int main()
{
    // 10/14 TODO: 先分别写整数筛选和WordCount筛选，再抽出模板。
    // 整数样例{1,4,2,5}，筛选>=3，预期{4,5}。
    // 词频样例red:2, blue:1, green:3，筛选count>=2，预期red,green。
    // TODO: 空输入、全不满足、原顺序不变；再调用一次标准算法对照。
    // TODO: 在文本项目的一个真实过滤需求中使用，解释定义的位置。
    std::cout << "Template lab: define select_matching before adding calls.\n";
    return 0;
}
