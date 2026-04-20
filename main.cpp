#include <Eigen/Dense>
#include <iostream>
#include <shape.h>
#include <tensor_backend.h>
int main() {

    auto tensor = utec::tf::Tensor<int>::from_data(utec::tf::Shape{2, 2}, {1, 2, 3, 4});
    (void)tensor(2, 0);
    return 0;

    // 1 20 6
}