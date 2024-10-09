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

#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Complex {
 public:
  Complex(double re, double im) : real_(re), img_(im) {}
  Complex() = default;
  double GetReal() const {return real_;}
  double GetMod() const {return real_;}
  double GetImg() const {return img_;}
  double GetAng() const {return img_;}

  Complex ToPolar() const;
  Complex ToBinomica() const;
  friend istream& operator>>(istream&, Complex&);
 private:
  double real_;
  double img_;
};
ostream& operator<<(ostream&, const Complex&);
Complex operator+ (const Complex&, const Complex&);
Complex operator- (const Complex&, const Complex&);
Complex operator* (const Complex&, const Complex&);
Complex operator/ (const Complex&, const Complex&);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Complex Complex::ToPolar() const {
  double mod, ang;
  mod = sqrt((real_ * real_) + (img_ * img_));
  ang = atan(img_ / real_);
  return Complex(mod, ang);
}

Complex Complex::ToBinomica() const {
  double real, img;
  real = real_* cos(img_);
  img = real_ * sin(img_);
  return Complex(real, img);
}



ostream& operator<<(ostream& out, const Complex& complejo) {
  out << complejo.GetReal() << " + " << complejo.GetImg() << "i" << endl;
  return out;
}

istream& operator>>(istream& is, Complex& com){
  is >> com.real_ >> com.img_;
  return is;
}

Complex operator+ (const Complex& com1, const Complex& com2) {
  return Complex(com1.GetReal() + com2.GetReal(), com1.GetImg() + com2.GetImg());
}

Complex operator- (const Complex& com1, const Complex& com2) {
  return Complex(com1.GetReal() - com2.GetReal(), com1.GetImg() - com2.GetImg());
}

Complex operator* (const Complex& a, const Complex& b) {
  Complex com1 = a.ToPolar();
  Complex com2 = b.ToPolar();
  Complex temp (com1.GetMod() * com2.GetMod(), com1.GetAng() + com2.GetAng());
  return temp.ToBinomica();
}

Complex operator/ (const Complex& a, const Complex& b) {
  Complex com1 = a.ToPolar();
  Complex com2 = b.ToPolar();
  Complex temp (com1.GetMod() / com2.GetMod(), com1.GetAng() - com2.GetAng());
  return temp.ToBinomica();
}