#include <iostream>
#include <string>
#include <vector>

// 先学习类、构造与const查询；到地图课程再加入Grid和enum class。
class Robot
{
public:
    // direction暂用'N'/'E'/'S'/'W'；非法参数采用什么策略请先约定。
    Robot(int row, int col, char direction);
    int row() const;
    int col() const;
    char direction() const;
    void turn_left();
    void turn_right();
    void forward();  // 第一阶段只改变坐标；接地图时再修改为可报告失败的接口。

private:
    int row_;
    int col_;
    char direction_;
};

// TODO: 在这里或main后定义成员函数。当前仅声明，尚未创建Robot实例。

int main()
{
    // 阶段1（9/23）：构造两个机器人，分别操作和查询。
    // 坐标约定：row向下增大，col向右增大。
    // TODO: 初始化、转向、前进、输出；比较两个对象互不影响。

    // 阶段2（9/26）：使用Grid管理地图、墙和边界。
    // TODO: 读字符地图；把direction改为enum class；执行F/L/R。
    // TODO: 前进失败要保持原位置，并报告命令位置。

    // 阶段3（9/27）：保存起始快照与历史，撤销一步、重放、执行N步。
    // TODO: 写清撞墙和无效命令是否进入历史，再实现。

    // 阶段4（10/3）：stack撤销、queue待执行命令、暂停和恢复。
    // TODO: 比较新容器和vector版本的同一段执行结果。

    // 阶段5（10/13）：见pathfinding.hpp与README，用BFS找路线。
    std::cout << "Robot scaffold: implement the current stage before running a simulation.\n";
    return 0;
}
