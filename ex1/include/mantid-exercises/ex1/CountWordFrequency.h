#include "mantid-exercises/ex1/DiscardWhile.h"
#include "mantid-exercises/ex1/TakeWhile.h"
#include "mantid-exercises/ex1/StripPunctuation.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

bool is_word_char(char candidate);
bool is_whitespace_char(char candidate);
std::string to_lower_case(std::string in);

template <typename CharInputIterator, typename Action>
void for_each_word(CharInputIterator begin, CharInputIterator end, Action action) {
    auto current = begin;
    while (current != end) {
        auto word_position_pair = take_while(current, end, &is_word_char);
        action(std::move(word_position_pair.first));
        current = word_position_pair.second;
        current = discard_while(current, end, &is_whitespace_char);
    }
}

template <typename CharInputIterator>
std::unordered_map<std::string, int> count_word_frequency(CharInputIterator begin,
                                                          CharInputIterator end) {
    auto word_frequency_map = std::unordered_map<std::string, int>{};
    for_each_word(begin, end, [&word_frequency_map](std::string word) -> void {
        auto constexpr MINIMUM_WORD_LENGTH = 4;
        word = strip_punctuation(word);
        if(word.size() > MINIMUM_WORD_LENGTH)
            word_frequency_map[to_lower_case(word)]++;
    });
    return word_frequency_map;
}

