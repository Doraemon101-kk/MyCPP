#pragma once

#include <cstddef>
#include <map>
#include <set>
#include <string>
#include <vector>

// 10/10迁移时：保持与你自己单文件版的接口一致，可调整这些声明。
struct WordCount
{
    std::string word;
    std::size_t count;
};

std::vector<std::string> tokenize(const std::string& text);
std::map<std::string, std::size_t> count_words(
    const std::vector<std::string>& words,
    const std::set<std::string>& stop_words);
std::vector<WordCount> top_words(
    const std::map<std::string, std::size_t>& counts, std::size_t k);
