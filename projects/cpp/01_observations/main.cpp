#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

struct Observation
{
    std::string id;
    double x;
    double y;
    double confidence;
};

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

bool find_nearest(
    const std::vector<Observation>& points,
    Observation& result,
    double reference_x = 0.0,
    double reference_y = 0.0);

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
std::vector<Observation> sort_by_distance(
    const std::vector<Observation> &points,
    double reference_x = 0.0,
    double reference_y = 0.0);
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

std::vector<Observation> sort_by_distance(
    const std::vector<Observation> &points,
    double reference_x,
    double reference_y)
{
    std::vector<Observation> sorted_points{points};

    std::sort(
        sorted_points.begin(),
        sorted_points.end(),
        [reference_x, reference_y](
            const Observation &a,
            const Observation &b
        ){
            if(distance_to_reference(a, reference_x, reference_y) <
        distance_to_reference(b, reference_x, reference_y)){
            return true;
        }
        if (distance_to_reference(a, reference_x, reference_y) >
            distance_to_reference(b, reference_x, reference_y))
        {
            return false;
        }
        return a.id < b.id;
    }

        );
    return sorted_points;
}

std::vector<Observation> TopK(
    const std::vector <Observation>& points, std::size_t k,
    double reference_x=0,
    double reference_y=0){
        auto sorted = sort_by_distance(points, reference_x, reference_y);
        std::size_t count = std::min(k, sorted.size());

        std::vector <Observation> result {};
        for(std::size_t i = 0; i< count;i++){
            result.push_back(sorted[i]);
        }
        return result;
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
    print_points(TopK(points, 0));
    print_points(TopK(points, 3));
    print_points(TopK(points, 10));
    return 0;
}
