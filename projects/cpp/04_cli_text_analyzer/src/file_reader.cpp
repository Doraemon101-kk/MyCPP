#include "file_reader.hpp"

#include <fstream>
#include <utility>

bool read_text_file(const std::string& file_path, std::string& content)
{
    content.clear();
    std::ifstream file(file_path);
    if (!file)
    {
        return false;
    }

    std::string result;
    char buffer[4096];
    while (file.read(buffer, sizeof(buffer)))
    {
        result.append(buffer, static_cast<std::size_t>(file.gcount()));
    }
    result.append(buffer, static_cast<std::size_t>(file.gcount()));
    if (file.bad() || !file.eof()) return false;

    content = std::move(result);
    return true;
}
