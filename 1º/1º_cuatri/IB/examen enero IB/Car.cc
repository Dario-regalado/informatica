/** 
 * Universidad de La Laguna
 * Escuela spuperiro de ingenieria y tecnologia
 * grado en ingenieria informatica
 * informtica basica 2023-24
 * 
 * @author Dario REgalado alu0101640150@ull.edu.es
 * @brief
 * @date enero 8 2024
*/

#include "Car.h"

std::istream& operator>>(std::istream& in, Car& coche1) {
  in >> coche1.model_ >> coche1.plate_ >> coche1.kilometers_;
  return in;
}

std::ostream& operator<<(std::ostream& out, const Car coche1) {
  out << coche1.model() << " " << coche1.plate() << " " << coche1.kilometers() << " ";
  return out;
}

bool operator<(const Car& coche1, const Car& coche2) {
  return (coche1.kilometers() < coche2.kilometers());
}

bool operator>(const Car& coche1, const Car& coche2) {
  return (coche1.kilometers() > coche2.kilometers());
}

int operator+(const Car& coche1, const Car& coche2) {
  return (coche1.kilometers() + coche2.kilometers());
}

