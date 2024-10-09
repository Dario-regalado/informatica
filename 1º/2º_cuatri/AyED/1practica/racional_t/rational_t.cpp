/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructura de Datos 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Feb 05 2024
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#include "rational_t.hpp"

//Construct a new rational_t object
rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// get the numerator
int
rational_t::get_num() const
{
  return num_;
}


// get the denominator
int
rational_t::get_den() const
{
  return den_;
}


// set the numerator 
void
rational_t::set_num(const int n)
{
  num_ = n;
}


// set the denominator
void
rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}


// calculates the division
double
rational_t::value() const
{ 
  return double(get_num()) / get_den();
}


// comparaciones

// checks if is equal r or not
bool
rational_t::is_equal(const rational_t& r, const double precision) const
{ 
  return bool(fabs(num_ * r.get_den() - den_ * r.get_num()) < precision);
}


//check if is greater than r or not
bool
rational_t::is_greater(const rational_t& r, const double precision) const
{
  return bool(value() - r.value() > precision);
}


// check if is less than r or not
bool
rational_t::is_less(const rational_t& r, const double precision) const
{
  return bool(r.value() - value() > precision);
}


// operaciones

// add two rational numbers
rational_t
rational_t::add(const rational_t& r)
{
  return rational_t ((num_ * r.get_den()) + (r.get_num() * den_), den_ * r.get_den());
}


// substract two rational numbers
rational_t
rational_t::substract(const rational_t& r)
{
  return rational_t ((num_ * r.get_den()) - (r.get_num() * den_), den_ * r.get_den());
}


// mmultiply two rational numbers
rational_t
rational_t::multiply(const rational_t& r)
{
  return rational_t (num_ * r.get_num(), den_ * r.get_den());
}


// divides two rational numbers
rational_t
rational_t::divide(const rational_t& r)
{
  return rational_t (num_ * r.get_den(), den_ * r.get_num());
}


// PRACTICA MODIFICADA
// substract a unity to the rational
rational_t rational_t::SubUnity() {
  return rational_t((num_ - den_), den_);
}



// E/S

// print on screen
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}


// reads from keyboard
void 
rational_t::read(istream& is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}

