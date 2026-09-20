#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

// 一条观测记录。先理解这些字段，再决定函数如何接收它。
struct Observation
{
    std::string id;
    double x;
    double y;
    double confidence;
};

// 省略参考点坐标时，默认使用原点 (0, 0)。
double distance_to_reference(
    const Observation& point,
    double reference_x = 0.0,
    double reference_y = 0.0);

std::vector<Observation> select_points(
    const std::vector<Observation>& points,
    double min_confidence,
    double max_distance,
    double reference_x = 0.0,
    double reference_y = 0.0);

// 空集合返回 false，且不修改 result；等距时保留先出现的记录。
bool find_nearest(
    const std::vector<Observation>& points,
    Observation& result,
    double reference_x = 0.0,
    double reference_y = 0.0);

// 修改传入的集合。
void translate_points(std::vector<Observation>& points, double dx, double dy)
{
    for (Observation& point : points){
        point.x += dx;
        point.y += dy;
    }
}
void print_points(const std::vector<Observation>& points){
    for(Observation point: points){
        std::cout << point.id<<"\t" <<point.x <<"\t"<<point.y <<"\n";
}}

double distance_to_reference(
    const Observation& point, double ref_x, double ref_y)
{
    return std::sqrt(
        (point.x - ref_x) * (point.x - ref_x) +
        (point.y - ref_y) * (point.y - ref_y));
}

// 返回新集合，不改变 points；边界值包含在筛选范围内。
std::vector<Observation> select_points(
    const std::vector<Observation>& points,
    double min_confidence,
    double max_distance,
    double reference_x,
    double reference_y)
{
    std::vector<Observation> selected_points;
    for (const Observation& point : points)
    {
        if (point.confidence >= min_confidence &&
            distance_to_reference(point, reference_x, reference_y) <= max_distance)
        {
            selected_points.push_back(point);
        }
    }
    return selected_points;
}

bool find_nearest(
    const std::vector<Observation>& points,
    Observation& result,
    double reference_x,
    double reference_y)
{
    if (points.empty())
    {
        return false;
    }

    result = points[0];
    for (const Observation& point : points)
    {
        if (distance_to_reference(point, reference_x, reference_y) <
            distance_to_reference(result, reference_x, reference_y))
        {
            result = point;
        }
    }
    return true;
}

int main()
{
    const std::vector<Observation> points{
        {"A", 3.0, 4.0, 0.9},
        {"B", 0.0, 2.0, 0.7},
        {"C", 6.0, 8.0, 0.95},
        {"D", -3.0, -4.0, 0.8},
        {"E", 1.0, 1.0, 0.4},
    };

    // 第一段：距离、筛选、最近点、平移和结果展示。
    print_points(points);
    auto selected = select_points(points, 0.6, 5);
    print_points(selected);
    Observation result{};
    if(find_nearest(selected, result)){
        std::cout << result.id<<"\n";
    }
    translate_points(selected, 1, -1);
    print_points(selected);
    print_points(points);
    // TODO 1: 实现距离与打印，输出全部原始记录。
    // TODO 2: 筛选置信度>=0.8且距离<=5的记录，展示结果。
    // TODO 3: 将阈值改成0.6，查找最近记录；调用前想好空结果处理。
    // TODO 4: 只平移筛选结果，再打印原集合，确认原集合没变。

    // 第二段：接着这个程序学参考点、自定义排序、lambda捕获。
    // TODO 5: 将距离改成“距给定参考点”；自行调整相关接口。
    // TODO 6: 排序副本：距离升序，同距离按id升序。
    // TODO 7: 返回最近K条；验证K=0、K超过数量和空集合。
    // TODO 8: 比较距离函数的重载与默认参数方案，选择一种保留。

    // 实现后用真正的调用替换这条提示；当前没有计算结果。
    std::cout
        << "Observation scaffold: " << points.size()
        << " sample records; TODO functions are not implemented.\n";
    return 0;
}
