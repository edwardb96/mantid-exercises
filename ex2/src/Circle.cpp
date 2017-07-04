#include "mantid-exercises/ex2/Circle.h"
#include <cmath>
#include <ostream>

Circle::Circle(double radius) : Shape{std::string{"Circle"}, 1}, m_radius{radius} {}

double Circle::diameter() const {
    return radius() * 2.0;
}

double Circle::perimeter() const {
    return diameter() * pi;
}

double Circle::radius() const {
    return m_radius;
}

double Circle::area() const {
    return pi * std::pow(radius(), 2);
}

void Circle::printAttributes(std::ostream& os) const {
    os << "radius: " << radius();
}
