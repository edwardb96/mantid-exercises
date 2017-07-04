#include <gtest/gtest.h>
#include <mantid-exercises/ex2/Square.h>
#include <cmath>

class SquareTest : public ::testing::Test {
protected:
    static auto constexpr side_length = 15.0;

    auto make_square() const {
        return Square{side_length};
    }
};

TEST_F(SquareTest, KnowsItsType) {
    auto const r = make_square();
    EXPECT_EQ(std::string{"Square"}, r.type());
}

TEST_F(SquareTest, KnowsItsSideCount) {
    auto const r = make_square();
    EXPECT_EQ(4, r.side_count());
}

TEST_F(SquareTest, KnowsItsPerimeter) {
    auto const r = make_square();
    EXPECT_DOUBLE_EQ(side_length * 4, r.perimeter());
}

TEST_F(SquareTest, KnowsItsArea) {
    auto const r = make_square();
    EXPECT_DOUBLE_EQ(std::pow(side_length, 2.0), r.area());
}
