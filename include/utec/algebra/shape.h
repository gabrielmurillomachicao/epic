#ifndef PROG3_PF_EPIC1_FEATURE1_V2026_01_SHAPE_H
#define PROG3_PF_EPIC1_FEATURE1_V2026_01_SHAPE_H
#include <vector>
namespace utec {
    namespace tf {
        class Shape {
            std::vector<int> data;
        public:
            Shape() = default;
            int operator[](int i)const {
                return data[i];
            };
            friend bool operator==(const Shape& lhs, const Shape& rhs) {
                return lhs.data == rhs.data;
            };
            explicit Shape (std::vector<int> data) : data(std::move(data)) {}
            Shape(int x, int y, int z) : data{x, y, z} {
                if (x<0 || y<0 || z<0) {
                    throw std::invalid_argument("Invalid shape");
                }
            }
            Shape(int x, int y):data{x,y} {
                if (x<=0||y<=0) {
                    throw std::invalid_argument("Shape parameters must be positive");
                }
            }
            std::vector<int> to_vector() {
                return data;
            }
            [[nodiscard]]long long rank() const {
                return static_cast<long long>(data.size());
            }
            [[nodiscard]]int numel() const {
                int respuesta=1;
                for (int i = 0; i < rank(); ++i) {
                    respuesta *= data[i];
                }
                return respuesta;
            }
        };

    }
}
using utec::tf::Shape;

#endif //PROG3_PF_EPIC1_FEATURE1_V2026_01_SHAPE_H