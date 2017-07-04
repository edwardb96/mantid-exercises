#include "mantid-exercises/ex1/CountWordFrequency.h"
#include <algorithm>

bool is_word_char(char candidate) {
    return !std::isspace(candidate);
}

bool is_whitespace_char(char candidate) {
    return std::isspace(candidate);
}

std::string to_lower_case(std::string in) {
    std::transform(in.begin(), in.end(), in.begin(), [](char mixed) -> auto {
        return std::tolower(mixed);
    });
    return in;
}
