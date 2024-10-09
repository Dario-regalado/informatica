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


#include "dependencies.h"

/** Shows correct usage of the program. 
  * If the program wasn't run correctly, prints the
  * help message.
  *
  * @param[in] argc Amount of arguments passed to the program
  * @param[in] argv Array of arguments
  */
void Usage(const int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " TEXT\n";
    std::cerr << "DESCRIPTION\n";
    std::exit(EXIT_FAILURE);
  }
}

int main(const int argc, char *argv[]) {
  Usage(argc, argv);
  int size{std::stoi(argv[1])};
  double lower{std::stod(argv[2])};
  double upper{std::stod(argv[3])};
  std::vector<double> my_vector = GenerateVector(size, lower, upper);
  for (int i{0}; i < my_vector.size(); ++i) {
    std::cout << my_vector[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "Max number of the vector is: " << MaxNumber(my_vector) << std::endl;
  std::cout << "Min number of the vector is: " << MinNumber(my_vector) << std::endl;
  std::cout << "Promedium number of the vector is: " << PromediumNumber(my_vector) << std::endl;
  return 0;
}
