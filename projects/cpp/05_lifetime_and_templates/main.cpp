// Learner implementations: do not replace TODOs with a complete AI solution.
#include <map>
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <memory>
#include <utility>
#include <string_view>

using WordCounts = std::map<std::string, int>;
using WordCountsReport = std::vector<std::pair<std::string, int>>;

// Same requirements, two separate implementations.
void remove_short_words_loop(std::vector<std::string>& words, std::size_t min_length);
void remove_short_words_erase_remove(std::vector<std::string>& words, std::size_t min_length);

// Chapter 3: erase all entries whose count < minimum; modify counts in place.
void remove_below(WordCounts& counts, int minimum)
{
    auto it = counts.begin();
    while(it != counts.end())
    {
        if(it->second >= minimum){
            ++it;
        }
        else{
            it = counts.erase(it);
        }
    }
}

// Chapter 3: delete words shorter than min_length; keep original relative order.
// First try a safe erase loop, then rewrite with the C++17 erase-remove idiom.
void remove_short_words_loop(std::vector<std::string>& words, std::size_t min_length)
{
    auto it = words.begin();
    while(it != words.end()){
        if(it->size() >= min_length){
            ++it;
        }else{
            it = words.erase(it);
        }
    }
}

// Version 2: fill this function body yourself with remove_if + range erase.
void remove_short_words_erase_remove(std::vector<std::string>& words, std::size_t min_length)
{
    auto logical_end = std::remove_if(
        words.begin(),
        words.end(),
        [min_length](const std::string& word){
            return word.size() < min_length;
        }
    );
    words.erase(logical_end, words.end());
}

// Chapter 4: preserve order; return owning copies selected by predicate.
template<class T, class Predicate>
std::vector<T> select_where(const std::vector<T>& input, Predicate predicate)
{
    std::vector<T> result;
    // Original learner implementation, kept for comparison:
    // for(const T& element: input)
    // {
    //     if(predicate(element)){
    //         result.push_back(element);
    //     }
    // }

    // Copy selected elements; the output iterator appends with push_back.
    std::copy_if(input.begin(), input.end(),
                 std::back_inserter(result), predicate);
    return result;
}

// Chapter 4 isolated ownership lab, not a recommendation to heap-allocate reports.
// The returned object owns its report, even after the argument's scope ends.
std::unique_ptr<WordCountsReport> keep_report(WordCountsReport report)
{
    // report is our own parameter object. Allow its vector storage to be moved
    // into a new report; make_unique returns that report's sole owner.
    // The returned owner keeps it alive after this function ends.
    return std::make_unique<WordCountsReport>(std::move(report));
}

// New exercise: implement HERE, leaving keep_report unchanged.
// Keep entries with count >= minimum. Return nullptr if none are selected.
std::unique_ptr<WordCountsReport> keep_selected_report(
    const WordCountsReport& source, int minimum)
{
    // Previous attempt, preserved for comparison:
    // select_where(report, [](int count){ count > minimum; ... });

    // TODO: collect selection -> handle empty result -> return its owner.
    auto result = select_where(
        source,
        [minimum](const auto &entry){
            return entry.second >= minimum;
    });

    if(!result.empty()){
        return std::make_unique<WordCountsReport>(std::move(result));
    }else{
        return nullptr;
    }
}

// Discuss ONLY; these fragments are intentionally not run:
// A. const auto& first=rows.front(); rows.push_back(...); use(first);
// B. const WordCountsReport& f(){ WordCountsReport local; return local; }
// C. for(auto it=counts.begin();it!=counts.end();++it)
//        if(it->second<minimum) counts.erase(it);
// D. std::string_view f(){ std::string local="hello"; return local; }
//    Why does returning the view by VALUE not make the characters live longer?
// E. A lambda captures &threshold and escapes its scope. What does it borrow?

int main(int argc,char** argv)
{
    try {
        const std::string chapter=argc>1?argv[1]:"all";
        if(chapter!="3" && chapter!="3-loop" && chapter!="3-erase-remove"
           && chapter!="4" && chapter!="all") {
            std::cerr<<"Usage: practice [3|3-loop|3-erase-remove|4|all]\n";
            return 1;
        }
        if(chapter!="4") {
            WordCounts counts{{"a",1},{"b",1},{"c",3},{"d",1},{"e",2}};
            remove_below(counts,2);
            assert((counts==WordCounts{{"c",3},{"e",2}}));
            remove_below(counts,4); assert(counts.empty());
            remove_below(counts,4); assert(counts.empty());
            WordCounts kept{{"a",1}}; remove_below(kept,1);
            assert((kept==WordCounts{{"a",1}}));
            if(chapter!="3-erase-remove") {
                std::vector<std::string> words{"a","b","cat","d","dog"};
                remove_short_words_loop(words,3);
                assert((words==std::vector<std::string>{"cat","dog"}));
                remove_short_words_loop(words,4); assert(words.empty());
                remove_short_words_loop(words,4); assert(words.empty());
                std::vector<std::string> no_filter{"", "a"};
                remove_short_words_loop(no_filter,0);
                assert((no_filter==std::vector<std::string>{"", "a"}));
                std::cout<<"Loop version checks passed\n";
            }
            if(chapter!="3-loop") {
                // Fresh inputs: the algorithm version must pass the SAME cases.
                std::vector<std::string> words{"a","b","cat","d","dog"};
                remove_short_words_erase_remove(words,3);
                assert((words==std::vector<std::string>{"cat","dog"}));
                remove_short_words_erase_remove(words,4); assert(words.empty());
                remove_short_words_erase_remove(words,4); assert(words.empty());
                std::vector<std::string> no_filter{"", "a"};
                remove_short_words_erase_remove(no_filter,0);
                assert((no_filter==std::vector<std::string>{"", "a"}));
                std::cout<<"Erase-remove version checks passed\n";
            }
            std::cout<<"Selected chapter 3 checks passed\n";
        }
        if(chapter=="4" || chapter=="all") {
            const std::vector<int> numbers{1,2,2,3,4};
            const auto original=numbers;
            assert((select_where(numbers,[](int x){return x%2==0;})==std::vector<int>{2,2,4}));
            assert(select_where(std::vector<int>{},[](int){return true;}).empty());
            assert(select_where(numbers,[](int){return false;}).empty());
            assert(numbers==original);
            const WordCountsReport rows{{"cat",2},{"dog",5},{"ant",2}};
            auto result=select_where(rows,[](const auto& row){return row.second>=3;});
            assert((result==WordCountsReport{{"dog",5}}));
            result.front().second=99; assert(rows[1].second==5);
            std::unique_ptr<WordCountsReport> owned;
            {
                WordCountsReport temporary{{"cat",2}};
                owned=keep_report(temporary);
                temporary.front().second=8;
            }
            assert(owned && owned->front().second==2);
            auto* borrowed=owned.get();
            auto next_owner=std::move(owned);
            assert(!owned && next_owner.get()==borrowed);
            next_owner.reset();
            // borrowed must not be dereferenced here; explain why.
            assert(!next_owner);
            std::cout<<"Chapter 4 baseline checks passed\n";
            const WordCountsReport source{{"cat",2},{"dog",5},{"ant",3}};
            const auto source_copy=source;
            auto selected_report=keep_selected_report(source,3);
            assert(selected_report);
            assert((*selected_report==WordCountsReport{{"dog",5},{"ant",3}}));
            selected_report->front().second=99;
            assert(source==source_copy);
            assert(!keep_selected_report(source,6));
            assert(!keep_selected_report({},3));
            std::cout<<"Chapter 4 variation checks passed\n";
        }
    } catch(const std::logic_error& e) {
        std::cerr<<"Not finished: "<<e.what()<<'\n'; return 2;
    }
}
