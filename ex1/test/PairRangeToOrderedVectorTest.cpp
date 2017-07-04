#include <gtest/gtest.h>
#include <mantid-exercises/ex1/PairRangeToOrderedVector.h>
#include <string>
#include <unordered_map>
#include <vector>

class PairRangeToOrderedVector : public ::testing::Test {
protected:
    auto false_comparison() {
        return [](auto&& a, auto&& b) -> auto {
            return false;
        };
    }

    template <typename ComparisonFunction>
    auto make_ordered_vector(std::unordered_map<std::string, int> const& map,
                             ComparisonFunction comp) {
        return ::make_ordered_vector<std::string, int>(map.begin(), map.end(), comp);
    }
};

TEST_F(PairRangeToOrderedVector, EmptyMapsToEmpty) {
    auto items  = std::unordered_map<std::string, int>{};
    auto result = make_ordered_vector(items, false_comparison());
    EXPECT_TRUE(result.empty());
}

TEST_F(PairRangeToOrderedVector, SingleItemMapsToSameSingleItem) {
    auto items = std::unordered_map<std::string, int>{};
    items.emplace(std::string{"hello"}, 10);
    auto result = make_ordered_vector(items, false_comparison());
    EXPECT_EQ((*items.begin()).first, (*result.begin()).first);
}

TEST_F(PairRangeToOrderedVector, ThreeItemsAreOrderedCorrectly) {
    auto items = std::unordered_map<std::string, int>{};
    items.emplace(std::string{"world"}, 2);
    items.emplace(std::string{"hello"}, 1);
    items.emplace(std::string{"mantid"}, 4);
    auto result = make_ordered_vector(
            items, [](auto&& a, auto&& b) -> auto { return a.second > b.second; });

    ASSERT_EQ(3ul, result.size());
    EXPECT_EQ(4, result[0].second);
    EXPECT_EQ(2, result[1].second);
    EXPECT_EQ(1, result[2].second);
}
