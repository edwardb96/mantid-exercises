#ifndef EX2_CIRCLE
#define EX2_CIRCLE
#include "mantid-exercises/ex2/Shape.h"

class Circle : public Shape {
public:
    static constexpr double pi = 3.14159265359;
    Circle(double radius);
    virtual double perimeter() const override;
    virtual double area() const override;
    virtual void printAttributes(std::ostream& os) const override;
private:
    double diameter() const;
    double radius() const;
    double m_radius;
};
#endif
