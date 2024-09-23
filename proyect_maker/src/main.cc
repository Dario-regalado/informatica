/**
 * @file main.cc
 * @author your name (you@domain.com)
 * @brief {reemplace} para nombre archivo
 *        (reemplace) para nombre clase
 * @version 0.1
 * @date 2024-09-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void Usage(const int argc, char* argv[]);
void CreateClass(const int n, char* argv[], const string&);
void CreateImpl(const int n, char* argv[], const string&);
void CreateMain(char* argv[], string);


int main(const int argc, char* argv[]) {
  Usage(argc, argv);
  string directory = argv[argc - 1];

  CreateMain(argv, directory);
  if (argc > 2){
  CreateClass(argc - 1, argv, directory);
  CreateImpl(argc - 1, argv, directory);
  }
  return 0;
}

/**
 * @brief Create a Class file
 * 
 * @param n 
 * @param argv 
 */
void CreateClass(const int n, char* argv[], const string& directory) {
  ofstream output_files;
  ifstream input_file;
  
  for (int i = 2; i < n; i++) {
    // Abrimos el archivo de salida para la clase
    output_files.open(directory + '/' + std::string(argv[i]) + ".h", std::ios::out);
    input_file.open("class_file.txt", std::ios::in);
    
    if (!input_file.is_open() || !output_files.is_open()) {
      cerr << "Error al abrir los archivos." << endl;
      return;
    }
    
    string line;
    while (getline(input_file, line)) {
      string words;
      istringstream input_stream(line);
      while (input_stream >> words) {
        if (words == "(reemplace)") {
          words = argv[i];
          words[0] = toupper(words[0]);  // Pone la primera letra en mayúscula

          // Reemplaza los guiones bajos por mayúsculas
          for (size_t j = 0; j < words.size(); j++) {
            if (words[j] == '_') {
              words.erase(j, 1);  // Borra el guion bajo
              words[j] = toupper(words[j]);  // Pone en mayúscula la letra siguiente
              j--;  // Ajustamos el índice para no saltar caracteres
            }
          }
        } else if (words == "{reemplace}") {
          words = argv[1];  // Reemplaza el nombre del archivo
        }
        output_files << words << ' ';  // Escribe la palabra con un espacio
      }
      output_files << '\n';  // Agrega salto de línea después de cada línea del archivo de entrada
    }
    
    output_files.close();
    input_file.close();
  }
}

/**
 * @brief Create a Impl file
 * 
 * @param n 
 * @param argv 
 */
void CreateImpl(const int n, char* argv[], const string& directory){
  ofstream output_files;
  ifstream input_file;
  
  for (int i = 2; i < n; i++) {
    // Abrimos el archivo de salida para la clase
    output_files.open(directory + '/' + std::string(argv[i]) + ".cc", std::ios::out);
    input_file.open("implementation_file.txt", std::ios::in);
    
    if (!input_file.is_open() || !output_files.is_open()) {
      cerr << "Error al abrir los archivos." << endl;
      return;
    }
    
    string line;
    while (getline(input_file, line)) {
      string words;
      istringstream input_stream(line);
      while (input_stream >> words) {
        if (words == "(reemplace)") {
          words = argv[i];
          words[0] = toupper(words[0]);  // Pone la primera letra en mayúscula

          // Reemplaza los guiones bajos por mayúsculas
          for (size_t j = 0; j < words.size(); j++) {
            if (words[j] == '_') {
              words.erase(j, 1);  // Borra el guion bajo
              words[j] = toupper(words[j]);  // Pone en mayúscula la letra siguiente
              j--;  // Ajustamos el índice para no saltar caracteres
            }
          }
        } else if (words == "{reemplace}") {
          words = argv[1];  // Reemplaza el nombre del archivo
        }
        output_files << words << ' ';  // Escribe la palabra con un espacio
      }
      output_files << '\n';  // Agrega salto de línea después de cada línea del archivo de entrada
    }
    
    output_files.close();
    input_file.close();
  }
}

/**
 * @brief Create a Main file
 * 
 * @param argv 
 */
void CreateMain(char* argv[], string directory){
  ofstream output_files;
  ifstream input_file;
  input_file.open("main_file.txt", std::ios::in);
  output_files.open(directory + '/' + argv[1] + string(".cc"), std::ios::out);;
  
  string line;
  while (getline(input_file, line)) {
    string word;
    istringstream line_stream(line);  // Convertimos la línea en un stream para leer palabra por palabra

    while (line_stream >> word) {
      if (word == "{reemplace}") {
        word = argv[1];  // Reemplazamos la palabra por el nombre del archivo
      }
      output_files << word << " ";
    }

    // Agregamos un salto de línea al final de cada línea procesada
    output_files << std::endl;
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
    std::cerr << "Usage: " << argv[0] << " nombre, clases(opcional), directorio\n";
    std::cerr << "nombre: nombre del proyecto\n";
    std::cerr << "clases: nombre de las clases necesarias\n";
    std::cerr << "directorio: ruta donde se aloja el proyecto\n";
    std::exit(EXIT_FAILURE);
  } else if(argc < 2){
    std::cerr << "Modo de empleo: " << argv[0] << " nombre_proyecto, (nombre de las clases), directorio final\n";
    std::cerr << "Pruebe " << argv[0] << "--help para mas informacion.\n";
    std::exit(EXIT_FAILURE);
  }
}