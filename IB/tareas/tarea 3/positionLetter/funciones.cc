/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 29 Oct 2023
  * @brief print the first position of a char in a string
  * @bug There are no known bugs
  */

#include <iostream>

int letterPosition (const std::string& string1, char letra){
  for (int i = 0; i < string1.length(); i++ ){
    if (string1[i] == letra){
      return i;
    }
  }
  return -1;
}