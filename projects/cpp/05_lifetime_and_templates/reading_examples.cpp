// Companion examples for the reading notes; learner main.cpp is unchanged.
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

using Report = std::vector<std::pair<std::string, int>>;

void remove_low_counts(std::map<std::string, int>& counts, int minimum)
{
    for (auto it = counts.begin(); it != counts.end();) {
        if (it->second < minimum) it = counts.erase(it);
        else ++it;
    }
}

void remove_short_loop(std::vector<std::string>& words, std::size_t minimum)
{
    for (auto it = words.begin(); it != words.end();) {
        if (it->size() < minimum) it = words.erase(it);
        else ++it;
    }
}

void remove_short_algorithm(std::vector<std::string>& words, std::size_t minimum)
{
    const auto end = std::remove_if(words.begin(), words.end(),
        [minimum](const std::string& word) { return word.size() < minimum; });
    words.erase(end, words.end());
}

template<class T, class Predicate>
std::vector<T> select_loop(const std::vector<T>& input, Predicate predicate)
{
    std::vector<T> output;
    for (const T& value : input) {
        if (predicate(value)) output.push_back(value);
    }
    return output;
}

template<class T, class Predicate>
std::vector<T> select_algorithm(const std::vector<T>& input, Predicate predicate)
{
    std::vector<T> output;
    std::copy_if(input.begin(), input.end(), std::back_inserter(output), predicate);
    return output;
}

std::unique_ptr<Report> own_report(Report report)
{
    return std::make_unique<Report>(std::move(report));
}

// Full reference for the planned prefix + count + sorting task.
// The notes explain where to stop if you want to attempt the exercise first.
Report select_report(const Report& source, std::string_view prefix, int minimum)
{
    auto output = select_algorithm(source,
        [prefix, minimum](const auto& entry) {
            const bool matches = entry.first.compare(0, prefix.size(), prefix) == 0;
            return matches && entry.second >= minimum;
        });
    std::sort(output.begin(), output.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });
    return output;
}

void capacity_demo()
{
    std::vector<int> values{10, 20};
    const auto index = std::size_t{0};
    std::cout << "Before: size=" << values.size()
              << " capacity=" << values.capacity()
              << " data=" << static_cast<const void*>(values.data()) << '\n';
    const auto old_capacity = values.capacity();
    // Requesting beyond current capacity forces reallocation.
    values.reserve(old_capacity + 1);
    std::cout << "After:  size=" << values.size()
              << " capacity=" << values.capacity()
              << " data=" << static_cast<const void*>(values.data()) << '\n';
    assert(values.size() == 2);
    assert(values.capacity() > old_capacity);
    assert(values[index] == 10); // Reacquire from the container, not an old pointer.
}

void capture_demo()
{
    int threshold = 3;
    auto by_value = [threshold](int n) { return n >= threshold; };
    auto by_reference = [&threshold](int n) { return n >= threshold; };
    threshold = 10;
    assert(by_value(5));
    assert(!by_reference(5)); // threshold is still alive here.
}

void ownership_demo()
{
    std::unique_ptr<Report> owner;
    {
        Report local{{"cat", 2}};
        owner = own_report(local);
        local.front().second = 9;
    }
    assert(owner && owner->front().second == 2);
    auto* borrowed = owner.get();
    auto new_owner = std::move(owner);
    assert(!owner);
    assert(new_owner.get() == borrowed);
    assert(borrowed->front().second == 2);
    new_owner.reset();
    assert(!new_owner);
    // borrowed is now dangling: never dereference it here.

    auto shared = std::make_shared<std::string>("shared value");
    auto second_owner = shared;
    shared.reset();
    assert(*second_owner == "shared value");
}

int main()
{
    std::map<std::string, int> counts{{"a", 1}, {"b", 1}, {"cat", 3}};
    remove_low_counts(counts, 2);
    assert((counts == std::map<std::string, int>{{"cat", 3}}));
    remove_low_counts(counts, 4);
    assert(counts.empty());
    remove_low_counts(counts, 4);

    for (const auto minimum : {std::size_t{0}, std::size_t{3}, std::size_t{8}}) {
        std::vector<std::string> a{"a", "b", "cat", "dog", ""};
        auto b = a;
        remove_short_loop(a, minimum);
        remove_short_algorithm(b, minimum);
        assert(a == b);
    }
    std::vector<std::string> empty;
    remove_short_algorithm(empty, 3);
    assert(empty.empty());

    const std::vector<int> numbers{1, 2, 2, 3, 4};
    const auto even = [](int n) { return n % 2 == 0; };
    assert((select_loop(numbers, even) == std::vector<int>{2, 2, 4}));
    assert(select_loop(numbers, even) == select_algorithm(numbers, even));
    assert(select_algorithm(numbers, [](int) { return false; }).empty());
    assert(select_algorithm(std::vector<int>{}, even).empty());
    const std::vector<std::string> words{"cat", "a", "dog", "tree"};
    assert((select_algorithm(words, [](const auto& s) { return s.size() >= 3; })
            == std::vector<std::string>{"cat", "dog", "tree"}));

    const Report source{{"cat", 2}, {"code", 5}, {"car", 5}, {"dog", 9}, {"cab", 3}};
    const auto original = source;
    auto report = select_report(source, "ca", 3);
    assert((report == Report{{"car", 5}, {"cab", 3}}));
    report.front().second = 99;
    assert(source == original);
    assert(select_report(source, "", 0).size() == source.size());
    assert(select_report(source, "long-prefix", 0).empty());
    assert(select_report(source, "ca", 99).empty());
    assert(select_report({}, "ca", 0).empty());
    assert((select_report(Report{{"cat", 3}, {"cab", 3}}, "ca", 3)
            == Report{{"cab", 3}, {"cat", 3}}));

    std::string text = "hello";
    std::string_view view = text;
    text[0] = 'H';
    assert(view == "Hello"); // No reallocation; owner still alive.
    capacity_demo();
    capture_demo();
    ownership_demo();
    std::cout << "All reading examples passed\n";
}
