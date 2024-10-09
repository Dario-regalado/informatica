/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Feb 05 2024
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#include "rational_t.hpp"
/**
 * @brief Construct a new rational t::rational t object
 * 
 * @param n 
 * @param d 
 */
RationalT::RationalT(const int n, const int d) {
  assert(d != 0);
  num_ = n, den_ = d;
}

/**
 * @brief Get de numerator
 * 
 * @return int 
 */
int RationalT::GetNum() const {
  return num_;
}



/**
 * @brief Get denominator
 * 
 * @return int 
 */
int RationalT::GetDen() const {
  return den_;
}



/**
 * @brief Set numerator
 * 
 * @param n 
 */
void RationalT::SetNum(const int n) {
  num_ = n;
}



/**
 * @brief Set denominator
 * 
 * @param d 
 * @return * void 
 */
void RationalT::SetDen(const int d) {
  assert(d != 0);
  den_ = d;
}



/**
 * @brief Calculates the division
 * 
 * @return double 
 */
double RationalT::Value() const {
  return double(GetNum()) / GetDen();
}


// comparaciones
/**
 * @brief 
 * 
 * @param r 
 * @param precision 
 * @return true 
 * @return false 
 */
bool RationalT::IsEqual(const RationalT& r, const double precision) const { 
  return bool(fabs(num_ * r.GetDen() - den_ * r.GetNum()) < precision);
}


/**
 * @brief 
 * 
 * @param r 
 * @param precision 
 * @return true 
 * @return false 
 */
bool RationalT::IsGreater(const RationalT& r, const double precision) const {
  return bool(Value() - r.Value() > precision);
}


/**
 * @brief 
 * 
 * @param r 
 * @param precision 
 * @return true 
 * @return false 
 */
bool RationalT::IsLess(const RationalT& r, const double precision) const {
  return bool(r.Value() - Value() > precision);
}


// operaciones
/**
 * @brief sum rational numbers
 * 
 * @param r 
 * @return RationalT 
 */
RationalT RationalT::Add(const RationalT& r) {
  RationalT racional_1((num_ * r.GetDen()) + (r.GetNum() * den_), den_ * r.GetDen());
  return racional_1;
}


/**
 * @brief substract rational numbers
 * 
 * @param r 
 * @return RationalT 
 */
RationalT RationalT::Substract(const RationalT& r) {
  return RationalT((num_ * r.GetDen()) - (r.GetNum() * den_), den_ * r.GetDen());
}


/**
 * @brief multiply rational numbers
 * 
 * @param r 
 * @return RationalT 
 */
RationalT RationalT::Multiply(const RationalT& r) {
  return RationalT(num_ * r.GetNum(), den_ * r.GetDen());
}


/**
 * @brief divide rational numbers
 * 
 * @param r 
 * @return RationalT 
 */
RationalT RationalT::Divide(const RationalT& r) {
  return RationalT(num_ * r.GetDen(), den_ * r.GetNum());
}



/**
 * @brief Print on screen
 * 
 * @param os 
 */
void RationalT::Write(std::ostream& os) const {
  os << GetNum() << "/" << GetDen() << " = " << Value() << std::endl;
}



/**
 * @brief Reads from keyboard
 * 
 * @param is 
 */
void RationalT::Read(std::istream& is) {
  std::cout << "Numerador? ";
  is >> num_;
  std::cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
