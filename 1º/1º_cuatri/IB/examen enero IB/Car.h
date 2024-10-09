/**
 * Universidad de La Laguna
 * Escuela de Ingenieria y Tecnologia
 * Grado en ingenieria informatica
 * Informatica Basica 2023-24
 * 
 * @author Dario Regalado Glez alu0101640150@ull.edu.es
 * @brief 
 * @date Enero 8 2024
 * 
 */
#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

class Car {
 public:
  Car (const std::string& modelo, const std::string& plate, const int km) : model_{modelo}, plate_{plate}, kilometers_{km} {}
  Car () = default;
  std::string model() const { return model_; }
  std::string plate() const { return plate_; }
  int kilometers() const { return kilometers_; }
  friend std::istream& operator>>(std::istream& in, Car& coche1);
 private:
  std::string model_;
  std::string plate_;
  int kilometers_;
};

std::ostream& operator<<(std::ostream& out, const Car coche1);
bool operator<(const Car& coche1, const Car& coche2);
bool operator>(const Car& coche1, const Car& coche2);
int operator+(const Car& coche1, const Car& coche2);

#endif