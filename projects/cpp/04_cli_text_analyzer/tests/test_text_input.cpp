#include "text_input.hpp"

#include <cassert>
#include <string>
#include <vector>

int main()
{
    using Words = std::vector<std::string>;

    assert(text::tokenize_ascii_lower("").empty());
    assert(text::tokenize_ascii_lower("... !!!").empty());
    assert((text::tokenize_ascii_lower("Hello, HELLO world!") ==
            Words{"hello", "hello", "world"}));
}
