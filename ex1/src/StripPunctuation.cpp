#include <mantid-exercises/ex1/StripPunctuation.h>
#include <algorithm>

bool is_punctuation(char candidate) {
    auto punctuation = std::string{".,?'\"!():'"};
    return std::find(punctuation.begin(), punctuation.end(), candidate) != punctuation.end();
}

std::string strip_punctuation(std::string in) {
    in.erase(std::remove_if(in.begin(), in.end(), &is_punctuation), in.end());
    return in;
}
