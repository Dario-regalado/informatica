/**
 * @file main.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-05-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "circel.h"

int main()  {
  Point2D punto(2, 5);
  Point2D punto2(4, 5);
  Point2D punto3(5, 5);
  Point2D punto4(7, 5);
  Point2D punto5(9, 5);
  //Circle circulo;
  std::cout << punto;
  std::cin >> punto;
  std::cout << punto;

  punto2 = 2 * punto;
  return 0;
}