#ifndef EX2_SQUARE
#define EX2_SQUARE
#include "mantid-exercises/ex2/Shape.h"
class Square : public Shape {
public:
    Square(double side_length);
    virtual double perimeter() const override;
    virtual double area() const override;
    void printAttributes(std::ostream& os) const override;
private:
    double side_length() const;
    double m_side_length;
};
#endif
