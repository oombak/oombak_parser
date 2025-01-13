#include "utils.hpp"

bool operator==(const Signal &lhs, const Signal &rhs) {
  return (lhs.name == rhs.name) && (lhs.type == rhs.type) &&
         (lhs.width == rhs.width);
}

std::ostream &operator<<(std::ostream &outs, const Signal &value) {
  return outs << "{ " << value.name << ", " << value.type << ", " << value.width
              << " }";
}
