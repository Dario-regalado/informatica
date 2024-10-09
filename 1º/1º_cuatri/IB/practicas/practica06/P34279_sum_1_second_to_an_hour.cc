/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @file P34279_sum_1_second_to_an_hour.cc
  * @author Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 22 Oct 2023
  * @brief add 1 second to an imput hour, minute and second
  * @bug There are no known bugs
  * @see https://jutge.org/problems/P48107
  */

#include <iostream>

int main() {
  int hora{0};
  int minutos{0};
  int segundos{0};

  std::cin >> hora >> minutos >> segundos;
  int total_de_segundos = hora * 3600 + minutos * 60 + segundos;
  ++total_de_segundos;
  hora = total_de_segundos / 3600;
  minutos  = (total_de_segundos % 3600) / 60;
  segundos = total_de_segundos % 60;
  if ((hora == 24) && (minutos == 0) && (segundos == 0)){
      std::cout << "00:00:00" << std::endl;
  } 
  else {    
    if (hora < 10) {
      std::cout << "0";
    }
    std::cout << hora << ":";

    if (minutos < 10) {
      std::cout << "0";
    }
    std::cout << minutos << ":";

    if (segundos < 10) {
      std::cout << "0";
    }
    std::cout << segundos << std::endl;
  }
  return 0;
}
