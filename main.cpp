#include <Eigen/Dense>
#include <iostream>
#include <shape.h>
#include <tensor_backend.h>
int main() {
    using utec::tf::Shape;
    using utec::tf::Tensor;

    auto tensor = Tensor<int>::from_data(Shape{2, 3}, {1, 2, 3, 4, 5, 6});
    tensor(0, 1) = 20;

    std::cout << tensor(0, 0) << ' ' << tensor(0, 1) << ' ' << tensor(1, 2) << '\n';
    // 1 20 6
}