/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 29 Oct 2023
  * @brief prints the N first terms of fibonacci serie
  * @bug There are no known bugs
  * @see https://jutge.org/problems/P48107
  */
 
#include <iostream>
#include <string>

bool CheckCorrectParameters(const int argc, char *argv[], const int kCorrectNumber);
void PrintProgramPurpose();
int FibonacciSerie(const int& N);