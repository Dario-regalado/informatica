/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Nov 21 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>

std::vector<double> CreateVector(const std::string& vector);
std::vector<double> ConcatenateVector (const std::vector<double>& vector1, const std::vector<double>& vector2);