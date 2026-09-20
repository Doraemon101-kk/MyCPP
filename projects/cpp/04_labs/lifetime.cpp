#include <iostream>
#include <string>
#include <vector>

class Trace
{
public:
    explicit Trace(const std::string& name);
    ~Trace();

private:
    std::string name_;
};

int main()
{
    // 9/28 TODO: 自己定义构造/析构，让它们打印name_。
    // TODO: 外层一个对象、内层两个对象，先写预测销毁顺序再运行。
    // TODO: 分别用值、引用、const引用传给小函数，解释对象是否被复制。
    // TODO: 纸面指出“返回局部对象引用”为什么失效，不实际解引用它。
    // TODO: 回到机器人项目，说明Robot/Grid对象各自的存活范围。
    std::cout << "Lifetime lab: define Trace and write a scoped experiment.\n";
    return 0;
}
