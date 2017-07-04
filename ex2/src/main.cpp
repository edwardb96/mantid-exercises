#include <mantid-exercises/ex2/Circle.h>
#include <mantid-exercises/ex2/Rectangle.h>
#include <mantid-exercises/ex2/Square.h>
#include <mantid-exercises/ex2/Triangle.h>
#include <mantid-exercises/ex2/ShapeSorter.h>
#include <iostream>
#include <memory>
#include <vector>

int main(int argc, char** argv) {
    auto square = std::make_unique<Square>(10.0);
    auto circle = std::make_unique<Circle>(5.0);
    auto triangle = std::make_unique<Triangle>(5.0, 10.0);
    auto rectangle = std::make_unique<Rectangle>(5.0, 15.0);
    
    auto shapes = std::vector<std::unique_ptr<Shape>>{};
    shapes.emplace_back(std::move(square));
    shapes.emplace_back(std::move(circle));
    shapes.emplace_back(std::move(triangle));
    shapes.emplace_back(std::move(rectangle));

    for(auto&& shape : shapes)
        std::cout << *shape << '\n';
    std::cout << std::endl;

    auto sorter = ShapeSorter{std::move(shapes)};
    sorter.print_with_n_sides(4);

    return 0;
}
