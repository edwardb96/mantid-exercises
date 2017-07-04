#include <gtest/gtest.h>
#include <mantid-exercises/ex2/Triangle.h>
#include <cmath>

class TriangleTest : public ::testing::Test {
protected:
    static auto constexpr base = 15.0;
    static auto constexpr height = 10.0;

    auto make_isoseles_triangle() const {
        return Triangle{base, height};
    }
};

TEST_F(TriangleTest, KnowsItsType) {
    auto const r = make_isoseles_triangle();
    EXPECT_EQ(std::string{"Triangle"}, r.type());
}

TEST_F(TriangleTest, KnowsItsSideCount) {
    auto const r = make_isoseles_triangle();
    EXPECT_EQ(3, r.side_count());
}

TEST_F(TriangleTest, KnowsItsPerimeter) {
    auto const r = make_isoseles_triangle();
    EXPECT_DOUBLE_EQ(base + (2 * std::hypot(base / 2, height)), r.perimeter());
}

TEST_F(TriangleTest, KnowsItsArea) {
    auto const r = make_isoseles_triangle();
    EXPECT_DOUBLE_EQ((base * height) / 2, r.area());
}
