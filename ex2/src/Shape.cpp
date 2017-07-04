#include "mantid-exercises/ex2/Shape.h"
#include <ostream>

Shape::Shape(std::string type, int side_count) : m_type{type}, m_side_count{side_count} {}

std::string Shape::type() const {
    return m_type;
}

int Shape::side_count() const {
    return m_side_count;
}

std::ostream& operator<<(std::ostream& os, Shape const& shape) {
    os << shape.type() << "(";
    shape.printAttributes(os);
    os << ")";
    return os;
}
