#include <string>
#include <utility>
#include <sstream>

template <typename CharInputIterator, typename CharPredicate>
std::pair<std::string, CharInputIterator> take_while(CharInputIterator begin,
                                                     CharInputIterator end,
                                                     CharPredicate should_take) {
    std::stringstream word_stream;
    auto current = begin;
    while (current != end && should_take(*current)) {
        word_stream << *current;
        current++;
    }
    return std::make_pair(word_stream.str(), current);
}
