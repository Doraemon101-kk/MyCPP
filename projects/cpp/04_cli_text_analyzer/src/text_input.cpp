#include "text_input.hpp"

#include <cctype>
#include <string>
#include <vector>

namespace text
{
std::vector<std::string> tokenize_ascii_lower(std::string_view input)
{
    std::vector<std::string> words;
    std::string current;

    for (const char raw : input)
    {
        const auto character = static_cast<unsigned char>(raw);
        if (std::isalpha(character) != 0)
        {
            current.push_back(
                static_cast<char>(std::tolower(character)));
        }
        else if (!current.empty())
        {
            words.push_back(current);
            current.clear();
        }
    }

    if (!current.empty())
    {
        words.push_back(current);
    }

    return words;
}
}
