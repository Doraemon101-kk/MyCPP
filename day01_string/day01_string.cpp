#include <iostream>
#include <string>

// 返回 text 中字符 target 出现的次数。
// 例如：count_char("banana", 'a') 应返回 3。
// 要求：使用范围 for 循环，并且不修改 text。
int count_char(const std::string& text, char target)
{
    // TODO: 在这里实现
    int count = 0;
    for(char c: text){
        if(c == target)
        {++count;}
    }
    return count;
}

int main()
{
    std::cout << "banana / a: "
              << count_char("banana", 'a')
              << " (expected 3)\n";

    std::cout << "hello / z: "
              << count_char("hello", 'z')
              << " (expected 0)\n";

    std::cout << "empty / x: "
              << count_char("", 'x')
              << " (expected 0)\n";

    return 0;
}
