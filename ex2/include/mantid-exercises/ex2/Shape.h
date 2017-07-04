#ifndef EX2_SHAPE
#define EX2_SHAPE 
#include <string>
class Shape {
public:
    Shape(std::string type, int side_count);
    std::string type() const;
    int side_count() const;
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
    virtual ~Shape() = default;
    friend std::ostream& operator<<(std::ostream& os, Shape const& shape);
private:
    virtual void printAttributes(std::ostream& os) const = 0;
    std::string m_type;
    int m_side_count;
};
#endif
