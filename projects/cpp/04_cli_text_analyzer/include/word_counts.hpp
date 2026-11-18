#pragma once

#include <cstddef>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <utility>

using WordCounts = std::map<std::string, int>;

WordCounts count_words(const std::vector<std::string> &words);
void remove_stop_word(WordCounts &counts, const std::set<std::string> &stop_words);
using WordCountsReport = std::vector<std::pair<std::string, int>>;

WordCountsReport make_report(int min_count, const WordCounts &counts, std::size_t k);
