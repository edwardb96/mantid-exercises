#include "mantid-exercises/ex2/Rectangle.h"
#include <ostream>

Rectangle::Rectangle(double width, double height)
    : Shape{std::string{"Rectangle"}, 4}, m_width{width}, m_height{height} {}

double Rectangle::perimeter() const {
    return 2 * height() + 2 * width();
}

double Rectangle::area() const {
    return height() * width();
}

double Rectangle::width() const {
    return m_width;
}

double Rectangle::height() const {
    return m_height;
}

void Rectangle::printAttributes(std::ostream& os) const {
    os << "width: " << width() << ", height: " << height();
}
