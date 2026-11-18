#include <iostream>
#include <string>
#include <vector>

class Grid
{
public:
    Grid(const std::vector<std::string>& cells);
    int rows() const;
    int cols() const;
    bool in_bounds(int row, int col) const;
    bool is_wall(int row, int col) const;
    bool can_enter(int row, int col) const;

private:
    std::vector<std::string> cells_;
};

Grid::Grid(const std::vector<std::string>& cells)
    : cells_(cells)
{
}

int Grid::rows() const
{
    return static_cast<int>(cells_.size());
}

int Grid::cols() const
{
    if (cells_.empty())
    {
        return 0;
    }

    return static_cast<int>(cells_[0].size());
}

enum class Direction
{
    North,
    West,
    East,
    South
};

class Robot
{
public:
    Robot(int row, int col, Direction direction);
    int row() const;
    int col() const;
    Direction direction() const;
    void turn_left();
    void turn_right();
    void forward();

private:
    int row_;
    int col_;
    Direction direction_;
};

char direction_to_char(Direction direction)
{
    switch (direction)
    {
    case Direction::North:
        return 'N';
    case Direction::East:
        return 'E';
    case Direction::South:
        return 'S';
    case Direction::West:
        return 'W';
    }

    return '?';
}

Robot::Robot(int row, int col, Direction direction)
    : row_(row), col_(col), direction_(direction)
{
}

int Robot::row() const
{
    return row_;
}

int Robot::col() const
{
    return col_;
}

Direction Robot::direction() const
{
    return direction_;
}

void Robot::turn_left()
{
    switch (direction_)
    {
    case Direction::North:
        direction_ = Direction::West;
        break;
    case Direction::West:
        direction_ = Direction::South;
        break;
    case Direction::South:
        direction_ = Direction::East;
        break;
    case Direction::East:
        direction_ = Direction::North;
        break;
    }
}

void Robot::turn_right()
{
    switch (direction_)
    {
    case Direction::North:
        direction_ = Direction::East;
        break;
    case Direction::East:
        direction_ = Direction::South;
        break;
    case Direction::South:
        direction_ = Direction::West;
        break;
    case Direction::West:
        direction_ = Direction::North;
        break;
    }
}

void Robot::forward()
{
    switch (direction_)
    {
    case Direction::North:
        row_ -= 1;
        break;
    case Direction::East:
        col_ += 1;
        break;
    case Direction::South:
        row_ += 1;
        break;
    case Direction::West:
        col_ -= 1;
        break;
    }
}

void print_robot(const std::string& name, const Robot& robot)
{
    std::cout
        << name << ": "
        << robot.row() << ' '
        << robot.col() << ' '
        << direction_to_char(robot.direction()) << '\n';
}

int main()
{
    Robot first(0, 0, Direction::East);
    Robot second(5, 5, Direction::North);

    first.forward();
    first.forward();
    first.turn_right();
    first.forward();

    std::cout << "expected first: 1 2 S\n";
    print_robot("actual first", first);

    std::cout << "expected second: 5 5 N\n";
    print_robot("actual second", second);

    const Robot observer(3, 4, Direction::West);
    std::cout << "expected const observer: 3 4 W\n";
    print_robot("actual const observer", observer);

    Robot variation(2, 2, Direction::North);
    variation.turn_left();
    variation.forward();
    variation.turn_right();
    variation.forward();

    std::cout << "expected variation: 1 1 N\n";
    print_robot("actual variation", variation);
    return 0;
}
