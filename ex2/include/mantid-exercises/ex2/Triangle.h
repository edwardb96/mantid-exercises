#ifndef EX2_TRIANGLE
#define EX2_TRIANGLE
#include "mantid-exercises/ex2/Shape.h"

class Triangle : public Shape {
public:
    Triangle(double base, double height);
    virtual double perimeter() const override; 
    virtual double area() const override;
    void printAttributes(std::ostream& os) const override;
private:
    double base() const;
    double height() const;
    double m_base;
    double m_height;
};
#endif
