#include <iostream>
#include <vector>

// 任务 1：返回 numbers 中所有元素的和。
// 要求：使用范围 for 循环，不修改 numbers。
int sum(const std::vector<int>& numbers)
{
    int total{0};
    // TODO: 在这里实现
    for(int number: numbers){
        total += number;
    }
    return total;
}

// 任务 2：将 numbers 中的每个元素扩大为原来的 2 倍。
// 要求：使用范围 for 循环，直接修改原 vector。
void double_values(std::vector<int>& numbers)
{
    // TODO: 在这里实现
    for(int&number: numbers){
        number*= 2;
    }
}

// 任务 3：统计 numbers 中严格大于 threshold 的元素个数。
// 要求：不修改 numbers。
int count_greater_than(const std::vector<int>& numbers, int threshold)
{
    // TODO: 在这里实现
    int count{0};
    for(int number: numbers){
        if(number > threshold){
            ++count;
        }
    }
    return count;
}

void print_vector(const std::vector<int>& numbers)
{
    for (const int number : numbers)
    {
        std::cout << number << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::vector<int> numbers{1, 3, 5, 7, 9};

    std::cout << "sum: " << sum(numbers) << " (expected 25)\n";
    std::cout << "greater than 4: "
              << count_greater_than(numbers, 4)
              << " (expected 3)\n";

    double_values(numbers);
    std::cout << "doubled: ";
    print_vector(numbers);
    std::cout << "expected: 2 6 10 14 18\n";

    return 0;
}
