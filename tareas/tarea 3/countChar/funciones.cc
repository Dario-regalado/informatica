/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 29 Oct 2023
  * @brief 
  * @bug There are no known bugs
  * @see https://jutge.org/problems/P48107
  */

#include <iostream>
#include <string>

int countVowels (const std::string& string1){
  int count{0};
  for (char palabra : string1){
    char lowerCase = tolower(palabra);
    if (palabra == 'a' || palabra == 'e' || palabra == 'i'|| palabra == 'o'|| palabra == 'u'){
      count++;
    }
  }
  return count;
}