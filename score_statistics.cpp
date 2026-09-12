#include <iostream>
#include <vector>

// 不断读取成绩并保存到 scores。
// 输入 -1 时结束录入；有效成绩范围是 0～100。
void input_scores(std::vector<int>& scores)
{
    while (true)
    {
        int score;
        std::cin >> score;

        if (score == -1)
        {
            break;
        }

        if (score >= 0 && score <= 100)
        {
            scores.push_back(score);
        }
    }
}

// 按录入顺序输出所有成绩。
void print_scores(const std::vector<int>& scores)
{
    for (int score : scores)
    {
        std::cout << score << ' ';
    }
    std::cout << '\n';
}

double calculate_average(const std::vector<int>& scores)
{
    double total{0.0};
    int count{0};

    for (int score : scores)
    {
        total += score;
        ++count;
    }

    return total / count;
}

int find_highest(const std::vector<int>& scores)
{
    int highest{-1};

    for (int score : scores)
    {
        if (score > highest)
        {
            highest = score;
        }
    }

    return highest;
}

int find_lowest(const std::vector<int>& scores)
{
    int lowest{101};

    for (int score : scores)
    {
        if (score < lowest)
        {
            lowest = score;
        }
    }

    return lowest;
}

int count_passed(const std::vector<int>& scores)
{
    int passed_count{0};

    for (int score : scores)
    {
        if (score >= 60)
        {
            ++passed_count;
        }
    }

    return passed_count;
}

int main()
{
    std::vector<int> scores;

    std::cout << "请输入成绩（输入 -1 结束）：\n";
    input_scores(scores);

    if (scores.empty())
    {
        std::cout << "没有有效成绩。\n";
        return 0;
    }

    std::cout << "已录入的成绩：";
    print_scores(scores);

    std::cout << "平均分：" << calculate_average(scores) << '\n';
    std::cout << "最高分：" << find_highest(scores) << '\n';
    std::cout << "最低分：" << find_lowest(scores) << '\n';
    std::cout << "及格人数：" << count_passed(scores) << '\n';

    return 0;
}
