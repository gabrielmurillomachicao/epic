#include <Eigen/Dense>
#include <iostream>
#include <shape.h>
#include <tensor_backend.h>
int main() {
    const auto tensor = utec::tf::Tensor<int>::from_data(utec::tf::Shape{2, 3}, {1, 2, 3, 4, 5, 6});
    const auto reshaped = tensor.reshape(utec::tf::Shape{3, 2});

    std::cout << reshaped.shape()[0] << ' ' << reshaped.shape()[1] << '\n';
    std::cout << reshaped(0, 0) << ' ' << reshaped(1, 1) << ' ' << reshaped(2, 1) << '\n';
    // 1 20 6
}