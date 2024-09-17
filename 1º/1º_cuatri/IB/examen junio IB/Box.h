#ifndef BOX
#define BOX
#include <iostream>

class Box {
 public:
  Box(const double length, const double breadth, const double height) : length_{length}, breadth_{breadth}, height_{height} {}
  Box() {}
  double length() const { return length_; }
  double breadth() const { return breadth_; }
  double height() const { return height_; }

  friend std::istream& operator>>(std::istream& in, Box& caja);
 private:
  double length_;
  double breadth_;
  double height_;
};

std::ostream& operator<<(std::ostream& out, const Box& caja1);
bool operator==(const Box& caja1, const Box& caja2);
#endif