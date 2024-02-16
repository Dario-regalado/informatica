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


class Racional {
 public:
  Racional(const int num = 0, const int den = 1);
  ~Racional() {}

  //getters
  int GetNum() const;
  int GetDen() const;

  //simplify
  Racional Simplify();

  void Write (std::ostream& os = std::cout);
 private:
  int num_, den_;
};

int MCD (const Racional& a, const Racional& b);
Racional operator+ (const Racional& r1, const Racional& r2);
std::ostream& operator<< (std::ostream& os, const Racional& r1);