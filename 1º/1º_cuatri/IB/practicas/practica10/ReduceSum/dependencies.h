/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Nov 20 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#pragma once
#include <iostream>
#include <cstdlib>
#include <vector> 
#include <random>

std::vector<double> GenerateVector(const int size, const double lower, const double upper);
double ReduceSum (const std::vector<double>& vector_return);
