#include "mantid-exercises/ex1/StripPunctuation.h"
#include <gtest/gtest.h>

class IsPunctuation : public ::testing::Test {
protected:
    auto is_punctuation(char candidate) {
        return ::is_punctuation(candidate);
    }
};

TEST_F(IsPunctuation, FullStop) {
    EXPECT_TRUE(is_punctuation('.'));
}

TEST_F(IsPunctuation, Paranthesis) {
    EXPECT_TRUE(is_punctuation('('));
}

TEST_F(IsPunctuation, Colon) {
    EXPECT_TRUE(is_punctuation(':'));
}

class StripPunctuation : public ::testing::Test {
protected:
    auto strip_punctuation(std::string const& word) {
        return ::strip_punctuation(word);
    }
};

TEST_F(StripPunctuation, EmptyStringRemainsEmpty) {
    EXPECT_EQ(std::string{}, strip_punctuation(std::string{}));
}

TEST_F(StripPunctuation, SingleCharRemainsTheSame) {
    EXPECT_EQ(std::string{"a"}, strip_punctuation(std::string{"a"}));
}

TEST_F(StripPunctuation, SingleColonBecomesEmptyString) {
    EXPECT_EQ(std::string{}, strip_punctuation(std::string{":"}));
}

TEST_F(StripPunctuation, SingleFullstopBecomesEmptyString) {
    EXPECT_EQ(std::string{}, strip_punctuation(std::string{"?"}));
}

TEST_F(StripPunctuation, RemovesSinglePunctuationMarkFromStartOfString) {
    EXPECT_EQ(std::string{"a"}, strip_punctuation(std::string{"!a"}));
}

TEST_F(StripPunctuation, RemovesSinglePunctionationMarkFromEndOfString) {
    EXPECT_EQ(std::string{"b"}, strip_punctuation(std::string{"b)"}));
}

TEST_F(StripPunctuation, RemovesSinglePunctuationMarkFromMiddleOfString) {
    EXPECT_EQ(std::string{"ab"}, strip_punctuation(std::string{"a\"b"}));
}

TEST_F(StripPunctuation, RemovedMultiplePunctuationMarksFromBegining) {
    EXPECT_EQ(std::string{"ab"}, strip_punctuation(std::string{"!!!ab"}));
}

TEST_F(StripPunctuation, RemovesMultiplePunctuationMarksFromEnd) {
    EXPECT_EQ(std::string{"ba"}, strip_punctuation(std::string{"ba:("}));
}

TEST_F(StripPunctuation, RemovesMultiplePunctuationMarksFromMiddle) {
    EXPECT_EQ(std::string{"ab"}, strip_punctuation(std::string{"a:!'b"}));
}

TEST_F(StripPunctuation, RemovesMultiplePunctuationGroups) {
    EXPECT_EQ(std::string{"abcd"}, strip_punctuation(std::string("a!b:c)d(")));
}

TEST_F(StripPunctuation, RemovesMultiplePunctuationGroupsOfVaryingLengths) {
    EXPECT_EQ(std::string{"abcd"}, strip_punctuation(std::string{"a!!:b:?c)d'''"}));
}
