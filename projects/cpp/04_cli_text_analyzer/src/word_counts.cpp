#include "word_counts.hpp"
#include <algorithm>

WordCounts count_words(const std::vector<std::string> &words)
{
    WordCounts word_tab {};
    for (const std::string &word: words)
    {
        word_tab[word] ++;

    }
    return word_tab;

}

void remove_stop_word(WordCounts &counts, const std::set<std::string> &stop_words)
{
    for(const std::string &word: stop_words)
    {
        counts.erase(word);
    }
}

WordCountsReport make_report(int min_count, const WordCounts &counts, std::size_t k)
{
    WordCountsReport reports{};
    for (const auto &entry : counts)
    {
        if (entry.second >= min_count){
            reports.push_back(entry);
        }
    }
    std::sort(reports.begin(), reports.end(),
              [](const auto& lhs, const auto& rhs)
              {
                  if (lhs.second != rhs.second)
                  {
                      return lhs.second > rhs.second;
                  }
                  return lhs.first < rhs.first;
              });
    if (k < reports.size())
    {
        reports.resize(k);
    }
    return reports;
}
