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

class Point2D {
 public:
  Point2D() = default;
  Point2D(int a, int b) : x_(a), y_(b) {}
  int GetX() const { return x_;}
  int GetY() const {return y_;}
  void SetX (int x) {x_ = x;}
  void SetY (int y) {y_ = y;}
  friend std::istream& operator>>(std::istream&, Point2D&);
  Point2D operator=(const Point2D& b);

 private:
  int x_, y_;
};

std::ostream& operator<<(std::ostream&, const Point2D&);
Point2D operator+(const Point2D&, const Point2D&);
Point2D operator*(const int, const Point2D&);
int operator*(const Point2D&, const Point2D&);




/**
 * @brief 
 * 
 * @param b 
 * @return Point2D 
 */
Point2D Point2D::operator=(const Point2D& b){
  return Point2D(b.GetX(), b.GetY());
}
/**
 * @brief 
 * 
 * @param a 
 * @param punto 
 * @return Point2D 
 */
Point2D operator*(const int a, const Point2D& punto){
  return Point2D(punto.GetX() * a, punto.GetY() * a);
}
/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int operator*(const Point2D& a, const Point2D& b) {
  return int(a.GetX() * b.GetX() + a.GetY() * b.GetY());
}
/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return Point2D 
 */
Point2D operator+(const Point2D& a, const Point2D& b){
  return Point2D(a.GetX() + b.GetX(), a.GetY() + b.GetY());
}
/**
 * @brief 
 * 
 * @param is 
 * @param punto_nuevo 
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& is, Point2D& punto_nuevo) {
  is >> punto_nuevo.x_ >> punto_nuevo.y_;
  return is;
}
/**
 * @brief 
 * 
 * @param os 
 * @param punto_nuevo 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Point2D& punto_nuevo) {
  os << punto_nuevo.GetX() << " " << punto_nuevo.GetY() << std::endl;
  return os;
}