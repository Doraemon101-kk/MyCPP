#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{1, 2, 2, 3, 2, 4};
    // 9/29 TODO: 删除所有值为2的元素；不能漏掉连续的两个2。
    // TODO: 测试全部删、全部留、空容器；分别观察size/capacity。
    // TODO: 追加元素前保存一个索引，追加后用索引重新定位有效元素。
    // TODO: 解释扩容为何可能使旧引用/迭代器失效，不对失效对象解引用。
    // TODO: 把同一删除逻辑用于机器人的轨迹记录。
    std::cout << "Vector lab: " << values.size() << " initial elements; TODO.\n";
    return 0;
}
