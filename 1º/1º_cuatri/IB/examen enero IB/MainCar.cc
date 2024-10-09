/** 
 * Universidad de la Laguna
 * escuela superior de ingenieria y tecnologia
 * grado en ingenieria informatica
 * informatica basica 2023-34
 * 
 * @author Dario Regalado alu0101640150@ull.edu.es
 * @brief
 * @date enero 8 2024
*/

#include <cstdlib>
#include "Car.h"

void Usage(const int argc, char*argv[]) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " param1, param2 and param3\n";
    std::cerr << "param1: a string with the model of the car\n";
    std::cerr << "param2: a string with the plate\n";
    std::cerr << "param 3: an integer with thw kilometers of the car\n";
    std::exit(EXIT_FAILURE);
  }
}

int main(const int argc, char* argv[]) {
  Usage(argc, argv);
  Car coche1{argv[1], argv[2], std::stoi(argv[3])};
  Car coche2{};
  std::cin >> coche2;
  if (coche1 > coche2) {
    std::cout << coche1 << "tiene mas km que: " << coche2 << std::endl;
  } else {
    std::cout << coche1 << " tiene menos km que " << coche2 << std::endl;
  }
}