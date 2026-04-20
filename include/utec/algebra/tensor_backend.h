//
    // Created by rudri on 10/11/2020.
    //

    #include "shape.h"
    #ifndef PROG3_PF_EPIC1_FEATURE1_V2026_01_TENSOR_BACKEND_H
    #define PROG3_PF_EPIC1_FEATURE1_V2026_01_TENSOR_BACKEND_H
    #include <vector>
    //using namespace std
    namespace utec {
    namespace tf {
        template<typename T>
        class Tensor {
            std::vector<T> values;//{1,2,3,4,5,6,7,8,9}
            std::vector<int> dim;//{3,3}(0,0,0)//2dim[1]=3
            int flatten(const std::vector<int>& coords) const{//{0,0}
                int index = 0;
                int mult = 1;
                for (int i = static_cast<int>(dim.size()) - 1; i >= 0; --i) {//{0,1}
                    index += coords[i] * mult;
                    mult *= dim[i];
                }

                return index;//int values[index]=valor en la coordenada
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
            static Tensor<T> from_data(Shape shape,std::vector<T> v) {
                if (shape.numel() != v.size()||shape.numel() ==0) {
                    throw std::invalid_argument("Shape must be the same size as Tensor");
                }
                Tensor<T> t;
                t.dim = shape.to_vector();
                t.values = v;
                return t;
            }
            size_t numel()  {
                return values.size();
            }
            Tensor reshape(Shape shape1) const {
                Shape shape2(dim);
                if (shape1.numel()!=shape2.numel()) {
                    throw std::invalid_argument("Shape must be the same size as Tensor");
                }
                Tensor t;
                t.dim = shape1.to_vector();
                t.values = values;
                return t;
            }
            const Tensor operator+(Tensor t1) const {
                Tensor t;
                t.dim = this->dim;
                t.values = this->values;
                if (t.dim==t1.dim) {
                    for (int i = 0; i < this->values.size(); ++i) {
                        t.values[i] += t1.values[i];
                    }
                }
                else {
                    throw std::invalid_argument("Cannot add tensor with dimensions not equal");
                }
                return t;
            }
            Tensor operator+(Tensor t1) {
                Tensor t;
                t.dim = this->dim;
                t.values = this->values;
                if (t.dim==t1.dim) {
                    for (int i = 0; i < this->values.size(); ++i) {
                        t.values[i] += t1.values[i];
                    }
                }
                else {
                    throw std::invalid_argument("Cannot add tensor with dimensions not equal");
                }
                return t;
            }

            template<typename... Args>
            T& operator()(Args... args) {
                std::vector<int> coords = {args...};
                if (coords.size()!=dim.size()) {
                    throw std::out_of_range("Shape must be the same size as Tensor");
                }
                for (int i=0; i<coords.size(); i++) {
                    if (coords[i] >= dim[i]) {
                        throw std::out_of_range("");
                    }
                }
                return values[flatten(coords)];
            }

            template<typename... Args>
            const T& operator()(Args... args) const {
                std::vector<int> coords = {args...};
                if (coords.size()!=dim.size()) {
                    throw std::out_of_range("Shape must be the same size as Tensor");
                }
                for (int i=0; i<coords.size(); i++) {
                    if (coords[i] >= dim[i]) {
                        throw std::out_of_range("");
                    }
                }
                return values[flatten(coords)];
            }

        };

    } // namespace tf
} // namespace utec
using utec::tf::Tensor;

#endif