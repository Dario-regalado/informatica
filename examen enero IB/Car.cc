#include "Car.h"

std::ostream& operator<<(std::ostream& out, const Car& coche) {
  out << coche.model() << coche.plate() << coche.kilometers();
  return out;
}

std::istream& operator>>(std::istream &in, Car &coche) {
  in >> coche.model_ >> coche.plate_ >> coche.kilometers_;
  return in;
}

bool operator<(const Car& coche1, const Car coche2) {
  return (coche1.kilometers() < coche2.kilometers());
}
bool operator>(const Car& coche1, const Car coche2) {
  return (coche1.kilometers() > coche2.kilometers());
}