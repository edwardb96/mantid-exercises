#include "mantid-exercises/ex2/ShapeSorter.h"
#include <algorithm>
#include <iostream>

ShapeSorter::ShapeSorter(ShapeList shapes) : m_shapes{std::move(shapes)} {}

void ShapeSorter::print_of_type(std::string type) const {
    print_where([type](auto&& shape) -> bool { return shape->type() == type; });
}

void ShapeSorter::print_with_n_sides(int side_count) const {
    print_where([side_count](auto&& shape) -> bool { return shape->side_count() == side_count; });
}

void ShapeSorter::print_ordered_by_descending_area() const {
    print_ordered_by(
            [](auto&& shapeA, auto&& shapeB) -> bool { return shapeA->area() > shapeB->area(); });
}

void ShapeSorter::print_ordered_by_descending_perimeter() const {
    print_ordered_by(
            [](auto&& shapeA, auto&& shapeB) -> bool { return shapeA->perimeter() > shapeB->perimeter(); });
}

void ShapeSorter::print_shape_range(ShapeList::const_iterator begin,
                                    ShapeList::const_iterator end) const {
    for (auto current = begin; current != end; current++)
        std::cout << **current << '\n';
    std::cout << std::endl;
}
