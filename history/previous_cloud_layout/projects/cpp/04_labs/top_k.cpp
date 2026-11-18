#include <algorithm>
#include <cstddef>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Entry
{
    std::string word;
    std::size_t count;
};

std::vector<Entry> top_k_sort(const std::vector<Entry>& entries, std::size_t k);
std::vector<Entry> top_k_heap(const std::vector<Entry>& entries, std::size_t k);

int main()
{
    const std::vector<Entry> entries{{"red", 2}, {"blue", 2}, {"green", 1}};
    // 10/12 TODO: 次数降序、同频词典序；分别用排序和保留K项的堆实现。
    // TODO: 堆保留的“当前最差候选”是谁？先手推K=2，再写比较器。
    // TODO: 两种结果相同；测试K=0/1/2/99、空输入、同频。
    // TODO: 比较O(n log n)与保留K项方案，不把计时偶然值当复杂度证明。
    std::cout << "TopK lab: " << entries.size() << " entries; implementations pending.\n";
    return 0;
}
