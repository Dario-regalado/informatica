/**
 * @file practicas.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include <iostream>
#include <cassert>
#include "practica.hpp"

Racional::Racional(const int num, const int den) {
  assert (den != 0);
  den_ = den;
  num_ = num;
}

int Racional::GetNum() const {
  return num_;
}
int Racional::GetDen() const {
  return den_;
}

void Racional::Write (std::ostream& os) {
  os << GetNum() << "/" << GetDen();
}

//operator add
Racional operator+ (const Racional& r1, const Racional& r2) {
  return ((r1.GetNum() * r2.GetDen()) + (r1.GetDen() * r2.GetNum()), r1.GetDen() * r2.GetDen());
}

//simplify

Racional Racional::Simplify() {
int r{0};
  do{
		r = num_ % den_;
		num_ = den_;
		den_ = r;
	} while(r);

}

std::ostream& operator<< (std::ostream& os, const Racional& r1) {
  os << r1.GetNum() << "/" << r1.GetDen() << " ";
  return os;
}