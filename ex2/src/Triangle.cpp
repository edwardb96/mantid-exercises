#include "mantid-exercises/ex2/Triangle.h"
#include <cmath>
#include <ostream>

Triangle::Triangle(double base, double height) : Shape{std::string{"Triangle"}, 3}, m_base{base}, m_height{height} {}

double Triangle::perimeter() const {
    return base() + (2 * std::hypot(base() / 2, height()));
}

double Triangle::area() const {
    return base() * height() / 2;
}

double Triangle::base() const {
    return m_base;
}

double Triangle::height() const {
    return m_height;
}

void Triangle::printAttributes(std::ostream& os) const {
    os << "base: " << base() << ", height: " << height();
}
