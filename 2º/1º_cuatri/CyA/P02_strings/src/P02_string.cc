/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 20/09/2024
  * @brief fichero del programa cliente, contiene una funcion para el 
  *        modo del uso del programa, una funcion que evalua los ficheros de
  *        entrada, una funcion que comprueba los ficheros y el main como director
  * @Practica 2: Cadenas y lenguajes
  * @bug There are no known bugs
  * @file cya-P02-P02_string
  */
 
#include <iostream>
#include <fstream>
#include "alphabet.h"
#include "word.h"
#include "language.h"
#include "symbol.h"

void Usage(const int argc, char* argv[]);
void ExecuteInput(std::ifstream& input_file, std::ofstream& output_file, const int accion);
bool EvaluateFile(const std::ifstream& input_file, const std::ofstream& output_file, char* argv[]);
bool EvaluateOpcode(const int);

int main(const int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream input_file;
  input_file.open(argv[1], std::ios::in);

  std::ofstream output_file;
  output_file.open(argv[2], std::ios::out);

  // si no se pudo abrir el archivo de entrada o salida, 
  // o el opcode no es válido, acaba el programa
  if(!EvaluateFile(input_file, output_file, argv) || EvaluateOpcode(std::stoi(argv[3]))) return 1;

  ExecuteInput(input_file, output_file, std::stoi(argv[3]));
  input_file.close();
  output_file.close();
  return 0;
}

/**
 * @brief lee del fichero de entrada la cadena y el alfabeto, y dependiendo 
 *        de lo elegido por el usuario, escribe en el fichero de salida
 * 
 * @param input_file 
 * @param output_file 
 * @param accion 
 */
void ExecuteInput(std::ifstream& input_file, std::ofstream& output_file, const int accion){
  while (input_file.good()){
    Alphabet alphabet;
    Word word;
    input_file >> word >> alphabet;
    switch (accion) {
    case 1:
      output_file << alphabet << '\n';
      std::cout << alphabet << '\n';
      break;
    case 2:
      output_file << word.GetLenght() << '\n';
      std::cout << word.GetLenght() << '\n';
      break;
    case 3:
      output_file << word.Reverse() << '\n';
      std::cout << word.Reverse() << '\n';
      break;
    case 4:
      output_file << word.Prefijo() << '\n';
      std::cout << word.Prefijo() << '\n';
      break;
    case 5:
      output_file << word.Sufijo() << '\n';
      std::cout << word.Sufijo() << '\n';
      break;
    default:
      break;
    }
  }
  
}

/** @brief Shows correct usage of the program. 
  *        If the program wasn't run correctly, prints the
  *        help message.
  *
  * @param[in] argc Amount of arguments passed to the program
  * @param[in] argv Array of arguments
  */
void Usage(const int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    std::cerr << "Usage: " << argv[0] << " param 1, param 2, param 3\n";
    std::cerr << "Param 1: fichero de entrada de las cadenas\n";
    std::cerr << "Param 2: fichero de salida\n";
    std::cerr << "Param 3: numero entero para realizar accion:\n";
    std::cerr << "1 Alfabeto, 2 Longitud, 3 Inversa, 4 Prefijo, 5 Sufijo.\n";
    std::cerr << "\n";
    std::exit(EXIT_FAILURE);
  } else if(argc != 4){
    std::cerr << "Modo de empleo: " << argv[1] << "filein.txt fileout.txt opcode\n";
    std::cerr << "Pruebe " << argv[1] << "--help para mas informacion.\n";
    std::exit(EXIT_FAILURE);
  }
}

/**
 * @brief evaluate if the files were opened correctly
 * 
 * @param input_file 
 * @param output_file 
 * @param argv 
 * @return true 
 * @return false 
 */
bool EvaluateFile(const std::ifstream& input_file, const std::ofstream& output_file, char* argv[]) {
  if(!input_file.is_open()) {
    std::cerr << "hubo un problema al abrir el archivo " << argv[1] << std::endl;
    return false;
  }
  if(!output_file.is_open()) {
    std::cerr << "hubo un problema al abrir el archivo " << argv[2] << std::endl;
    return false;
  }
  return true;
}

/**
 * @brief evaluate if the opcode is correct
 * 
 * @param opcode 
 * @return true 
 * @return false 
 */
bool EvaluateOpcode(const int opcode){
  return(isalnum(opcode) && opcode <= 5 && opcode >= 0);
}