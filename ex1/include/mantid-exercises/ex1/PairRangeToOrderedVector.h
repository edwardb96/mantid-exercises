#include <algorithm>
#include <vector>

template <typename First, typename Second, typename PairInputIterator, typename ComparisonFunction>
std::vector<std::pair<First, Second>> make_ordered_vector(PairInputIterator begin,
                                                          PairInputIterator end,
                                                          ComparisonFunction compare) {
    auto ordered = std::vector<std::pair<First, Second>>{begin, end};
    std::sort(ordered.begin(), ordered.end(), compare);
    return ordered;
}
