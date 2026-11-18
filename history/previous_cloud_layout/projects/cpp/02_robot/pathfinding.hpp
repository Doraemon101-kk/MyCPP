#pragma once

#include <string>
#include <vector>

// 10/13寻路课程再使用，不是第一天的必读接口。
struct Position
{
    int row;
    int col;
};

// 输入为合法矩形地图；#不可走，其余字符可走；只走上下左右。
// 成功：path含起点和终点；失败：path清空，返回false。
// 最短路径不唯一时，返回任意一条合法最短路径。
bool shortest_path(const std::vector<std::string>& grid,
                   Position start,
                   Position goal,
                   std::vector<Position>& path);

// TODO: 自己实现搜索、前驱记录与路径恢复，不在这里预填算法。
