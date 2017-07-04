#include "mantid-exercises/ex1/CountWordFrequency.h"
#include <gtest/gtest.h>

class DiscardWhitespace : public ::testing::Test {
protected:
    auto take_whitespace(std::string const& word) {
        return ::discard_while(word.begin(), word.end(), &is_whitespace_char);
    }
};

TEST_F(DiscardWhitespace, StopsAtEnd) {
    auto const empty  = std::string{};
    auto const result = take_whitespace(empty);

    EXPECT_EQ(result, empty.end());
}

TEST_F(DiscardWhitespace, StopsAtEndOfSpace) {
    auto const empty  = std::string{" "};
    auto const result = take_whitespace(empty);

    EXPECT_EQ(result, empty.end());
}

TEST_F(DiscardWhitespace, StopsAtEndOfManySpaces) {
    auto const many_spaces = std::string{"       "};
    auto const result      = take_whitespace(many_spaces);

    EXPECT_EQ(result, many_spaces.end());
}

TEST_F(DiscardWhitespace, StopsAtBeginingOfWordOnlyString) {
    auto const word_only = std::string{"apples"};
    auto const result    = take_whitespace(word_only);

    EXPECT_EQ(result, word_only.begin());
}

TEST_F(DiscardWhitespace, StopsAtFirstCharOfWordWithSpacesPrepended) {
    auto const spaces_before_word = std::string{"    apples"};
    auto const result             = take_whitespace(spaces_before_word);

    EXPECT_EQ(*result, 'a');
}

TEST_F(DiscardWhitespace, StopsAtFirstCharOfWordWithNewlinesPrepended) {
    auto const newlines_before_word = std::string{"\n\n\napples"};
    auto const result               = take_whitespace(newlines_before_word);

    EXPECT_EQ(*result, 'a');
}

TEST_F(DiscardWhitespace, StopsAtFirstCharOfWordWithMixedWhitespacePrepended) {
    auto const whitespace_before_word = std::string{"   \n\n\n  \n Bananas"};
    auto const result                 = take_whitespace(whitespace_before_word);

    EXPECT_EQ(*result, 'B');
}

