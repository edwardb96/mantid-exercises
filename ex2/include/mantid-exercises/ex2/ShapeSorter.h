#include "mantid-exercises/ex2/Shape.h"
#include <algorithm>
#include <memory>
#include <string>
#include <vector>

class ShapeSorter {
    using ShapeList = std::vector<std::unique_ptr<Shape>>;

public:
    ShapeSorter(ShapeList shapes);
    void print_of_type(std::string type) const;
    void print_with_n_sides(int side_count) const;
    void print_ordered_by_descending_area() const;
    void print_ordered_by_descending_perimeter() const;

private:
    void print_shape_range(ShapeList::const_iterator begin, ShapeList::const_iterator end) const;
    template <typename Predicate>
    void print_where(Predicate predicate) const;
    template <typename OrderingFunction>
    void print_ordered_by(OrderingFunction order) const;

    ShapeList mutable m_shapes;
};

template <typename OrderingFunction>
void ShapeSorter::print_ordered_by(OrderingFunction order) const {
    std::sort(m_shapes.begin(), m_shapes.end(), order);
    print_shape_range(m_shapes.begin(), m_shapes.end());
}

template <typename Predicate>
void ShapeSorter::print_where(Predicate predicate) const {
    auto end = std::remove_if(
            m_shapes.begin(), m_shapes.end(), [predicate](auto&& item) -> bool { return !predicate(item); });
    print_shape_range(m_shapes.begin(), end);
}
