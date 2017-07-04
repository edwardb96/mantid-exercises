#ifndef EX2_RECTANGLE
#define EX2_RECTANGLE
#include "mantid-exercises/ex2/Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(double width, double height);
    double perimeter() const override;
    double area() const override;
    void printAttributes(std::ostream& os) const override;
private:
    double width() const;
    double height() const;
    double m_width;
    double m_height;
};
#endif
