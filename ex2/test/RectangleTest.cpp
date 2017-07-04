#include <gtest/gtest.h>
#include <mantid-exercises/ex2/Rectangle.h>
#include <cmath>

class RectangleTest : public ::testing::Test {
protected:
    static auto constexpr width = 15.0;
    static auto constexpr height = 10.0;

    auto make_rectangle() const {
        return Rectangle{width, height};
    }
};

TEST_F(RectangleTest, KnowsItsType) {
    auto const r = make_rectangle();
    EXPECT_EQ(std::string{"Rectangle"}, r.type());
}

TEST_F(RectangleTest, KnowsItsSideCount) {
    auto const r = make_rectangle();
    EXPECT_EQ(4, r.side_count());
}

TEST_F(RectangleTest, KnowsItsPerimeter) {
    auto const r = make_rectangle();
    EXPECT_DOUBLE_EQ(width * 2 + height * 2, r.perimeter());
}

TEST_F(RectangleTest, KnowsItsArea) {
    auto const r = make_rectangle();
    EXPECT_DOUBLE_EQ(width * height, r.area());
}
