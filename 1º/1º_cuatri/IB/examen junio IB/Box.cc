#include "Box.h"


std::ostream& operator<<(std::ostream& out, const Box& caja1) {
  out << caja1.length() << " " << caja1.breadth() << " " << caja1.height() << std::endl;
  return out;
}

std::istream& operator>>(std::istream& in, Box& caja) {
  in >> caja.length_ >> caja.breadth_ >> caja.height_;
  return in;
}

bool operator==(const Box& caja1, const Box& caja2) {
  return (caja1.length() == caja2.length() && caja1.breadth() == caja2.breadth() && caja1.height() == caja2.height());
}