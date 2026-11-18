#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace text
{
std::vector<std::string> tokenize_ascii_lower(std::string_view input);
}
