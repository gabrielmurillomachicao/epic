//
    // Created by rudri on 10/11/2020.
    //

    #include "shape.h"
    #ifndef PROG3_PF_EPIC1_FEATURE1_V2026_01_TENSOR_BACKEND_H
    #define PROG3_PF_EPIC1_FEATURE1_V2026_01_TENSOR_BACKEND_H

    #include <vector>

    namespace utec {
    namespace tf {

        template<typename T>
        class Tensor {
            std::vector<T> values;
            std::vector<int> dim;
            int flatten(const std::vector<int>& coords) const {
                int index = 0;
                int mult = 1;

                for (int i = static_cast<int>(dim.size()) - 1; i >= 0; --i) {
                    index += coords[i] * mult;
                    mult *= dim[i];
                }

                return index;
            }


        public:
            Tensor() = default;
            Shape shape() const{
                return Shape(dim);
            }
             int numel() const {
                Shape shape(dim);
                return shape.numel();
            }
             int rank() const {
                Shape shape(dim);
                return shape.rank();
            }
            static Tensor<T> zeros(Shape shape) {
                Tensor<T> t;
                t.dim = shape.to_vector();
                t.values = std::vector<T>(shape.numel(), 0);
                return t;
            }

            static Tensor<T> ones(Shape shape) {
                Tensor<T> t;
                t.dim = shape.to_vector();
                t.values = std::vector<T>(shape.numel(), 1);
                return t;
            }

            size_t numel()  {
                return values.size();
            }

            template<typename... Args>
            T& operator()(Args... args) {
                std::vector<int> coords = {args...};
                return values[flatten(coords)];
            }

            template<typename... Args>
            const T& operator()(Args... args) const {
                std::vector<int> coords = {args...};
                return values[flatten(coords)];
            }
        };

    } // namespace tf
} // namespace utec

#endif