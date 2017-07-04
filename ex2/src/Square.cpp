#include "mantid-exercises/ex2/Square.h"
#include <cmath>
#include <ostream>

Square::Square(double side_length) : Shape{"Square", 4}, m_side_length{side_length} {}

double Square::perimeter() const {
    return 4 * side_length();
}

double Square::area() const {
    return std::pow(side_length(), 2.0);
}

double Square::side_length() const {
    return m_side_length;
}

void Square::printAttributes(std::ostream& os) const {
    os << "side_length: " << side_length();
}
