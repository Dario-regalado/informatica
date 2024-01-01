#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>

class Car {
 public:
  Car(const std::string& model, const std::string plate, const int kilometers) : model_{model}, plate_{plate}, kilometers_{kilometers} {}
  Car() {}

  std::string model() const { return model_; }
  std::string plate() const { return plate_; }
  int kilometers() const { return kilometers_; }

  friend std::istream& operator>>(std::istream &in, Car &coche);
 private:
  std::string model_;
  std::string plate_;
  int kilometers_;
};
bool operator>(const Car& coche1, const Car coche2);
bool operator<(const Car& coche1, const Car coche2);
std::ostream& operator<<(std::ostream& out, const Car& coche);

#endif