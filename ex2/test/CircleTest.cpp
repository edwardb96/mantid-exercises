#include <gtest/gtest.h>
#include <mantid-exercises/ex2/Circle.h>
#include <cmath>

class CircleTest : public ::testing::Test {
protected:
    static auto constexpr radius = 10.0;
    auto make_circle() const {
        return Circle{radius};
    }
};

TEST_F(CircleTest, KnowsItsType) {
    auto c = make_circle();
    EXPECT_EQ(std::string{"Circle"}, c.type());
}

TEST_F(CircleTest, KnowsItsSideCount) {
    auto c = make_circle();
    EXPECT_EQ(1, c.side_count());
}

TEST_F(CircleTest, KnowsItsPerimeter) {
    auto c = make_circle();
    EXPECT_DOUBLE_EQ((radius * 2) * Circle::pi, c.perimeter());
}

TEST_F(CircleTest, KnowsItsArea) {
    auto c = make_circle();
    EXPECT_DOUBLE_EQ(Circle::pi * std::pow(radius, 2), c.area());
}
