#include "file_reader.hpp"

#include <cassert>
#include <cstdio>
#include <fstream>
#include <string>

int main()
{
    const std::string path = "file_reader_test_tmp.txt";
    {
        std::ofstream file(path);
        assert(file);
        file << "Hello world";
        assert(file);
    }

    std::string content = "old";
    assert(read_text_file(path, content));
    assert(content == "Hello world");

    {
        std::ofstream file(path, std::ios::trunc);
        assert(file);
    }
    assert(read_text_file(path, content));
    assert(content.empty());

    assert(std::remove(path.c_str()) == 0);
    content = "old";
    assert(!read_text_file(path, content));
    assert(content.empty());
}
