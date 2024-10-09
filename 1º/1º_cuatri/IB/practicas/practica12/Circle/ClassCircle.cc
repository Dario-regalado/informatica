/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Dec 03 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */


#include "ClassCircle.h"

double Cirlce::Area() {
  return M_PI * radio_ * radio_;
}
double Cirlce::Preimetro() {
  return 2 * M_PI * radio_;
}
void Cirlce::Print() {
  std::cout << this->Area() << " " << this->Preimetro() << " " << this->color_ << std::endl; 
}

void Cirlce::EsInterior(const Point2D &punto_a_comprobar) {
  double es_interior{sqrt(pow(punto_a_comprobar.GetX() - centro_.GetX(), 2) + pow(punto_a_comprobar.GetY() - centro_.GetY(), 2))};
  if (es_interior > radio_) {
    std::cout << "el punto esta fuera del circulo\n";
  } else {
    std::cout << "es punto esta dentro del circulo\n";
  }
}
