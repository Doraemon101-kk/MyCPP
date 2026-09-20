#pragma once
#include <vector>

// 10/14 TODO: 在头文件补定义；返回满足predicate的元素，保留原顺序。
// 输入不改变；Predicate是可调用对象，接收元素并返回可作为bool的值。
template <typename T, typename Predicate>
std::vector<T> select_matching(const std::vector<T>& values, Predicate predicate);
