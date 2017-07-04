template <typename CharInputIterator, typename CharPredicate>
CharInputIterator discard_while(CharInputIterator begin,
                                CharInputIterator end,
                                CharPredicate should_discard) {
    auto current = begin;
    while (current != end && should_discard(*current)) {
        current++;
    }
    return current;
}

