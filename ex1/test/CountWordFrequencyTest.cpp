#include "mantid-exercises/ex1/CountWordFrequency.h"
#include <gtest/gtest.h>

class CountWordFrequency : public ::testing::Test {
protected:
    auto count_word_frequency(std::string in) {
        return ::count_word_frequency(in.begin(), in.end());
    }

    int frequency(std::unordered_map<std::string, int> const& frequency_map,
                  std::string const& key) {
        return (*frequency_map.find(key)).second;
    }
};

TEST_F(CountWordFrequency, NoEntriesForEmptyString) {
    auto const empty  = std::string{};
    auto const result = count_word_frequency(empty);

    EXPECT_TRUE(result.empty());
}

TEST_F(CountWordFrequency, OneEntryForSingleWordString) {
    auto const single_word = std::string{"mantid"};
    auto const result      = count_word_frequency(single_word);

    ASSERT_EQ(1ul, result.size());
    EXPECT_EQ(1, frequency(result, single_word));
}

TEST_F(CountWordFrequency, TwoEntriesForDoubleWordString) {
    auto const first_word  = std::string{"mantid"};
    auto const second_word = std::string{"project"};
    auto const input       = first_word + " \n" + second_word;
    auto const result      = count_word_frequency(input);

    ASSERT_EQ(2ul, result.size());
    EXPECT_EQ(1, frequency(result, first_word));
    EXPECT_EQ(1, frequency(result, second_word));
}

TEST_F(CountWordFrequency, TrippleWordStringWithOneRepeatedWord) {
    auto const first_word  = std::string{"mantid"};
    auto const second_word = std::string{"project"};
    auto const input       = first_word + " \n" + second_word + " " + first_word;
    auto const result      = count_word_frequency(input);

    ASSERT_EQ(2ul, result.size());
    EXPECT_EQ(2, frequency(result, first_word));
    EXPECT_EQ(1, frequency(result, second_word));
}

TEST_F(CountWordFrequency, IsCaseInsensitive) {
    auto const single_word = std::string{"mantid"};
    auto const input       = single_word + " manTID Mantid";
    auto const result      = count_word_frequency(input);

    ASSERT_EQ(1ul, result.size());
    EXPECT_EQ(3, frequency(result, single_word));
}

TEST_F(CountWordFrequency, IsPunctuationInsensitive) {
    auto const single_word = std::string{"project"};
    auto const input = single_word + std::string{" pro'ject"};
    auto const result = count_word_frequency(input);

    ASSERT_EQ(1ul, result.size());
    EXPECT_EQ(2, frequency(result, single_word));
}

TEST_F(CountWordFrequency, IgnoresSmallWords) {
    auto const small_word = std::string{"proj"};
    auto const result = count_word_frequency(small_word);

    EXPECT_TRUE(result.empty());
}

TEST_F(CountWordFrequency, IgnoresSmallWordsWhenMadeSmallByPunctuationElimination) {
    auto const small_word = std::string{"doo'r"};
    auto const result = count_word_frequency(small_word);

    EXPECT_TRUE(result.empty());
}
