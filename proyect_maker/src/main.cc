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
void CreateMain(char* argv[], const string&);


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
      size_t pos = 0;

      // Reemplazamos todas las ocurrencias de "(reemplace)" por argv[i]
      while ((pos = line.find("(reemplace)", pos)) != string::npos) {
        string class_name = argv[i];
        class_name[0] = toupper(class_name[0]);  // Pone la primera letra en mayúscula

        // Reemplaza guiones bajos por mayúsculas
        for (size_t j = 0; j < class_name.size(); j++) {
          if (class_name[j] == '_') {
            class_name.erase(j, 1);  // Borra el guion bajo
            class_name[j] = toupper(class_name[j]);  // Pone en mayúscula la letra siguiente
            j--;  // Ajusta el índice
          }
        }

        // Reemplaza "(reemplace)" por el nombre de la clase formateado
        line.replace(pos, 11, class_name);
        pos += class_name.size();  // Avanza el índice después del reemplazo
      }

      // Reemplazamos todas las ocurrencias de "{reemplace}" por argv[1] (nombre del archivo)
      pos = 0;
      while ((pos = line.find("{reemplace}", pos)) != string::npos) {
        line.replace(pos, 11, argv[1]);
        pos += string(argv[1]).size();  // Avanza el índice después del reemplazo
      }

      // Escribimos la línea completa, conservando los espacios iniciales
      output_files << line << '\n';
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
void CreateImpl(const int n, char* argv[], const string& directory) {
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
      size_t pos = 0;

      // Reemplazamos todas las ocurrencias de "(reemplace)" por argv[i]
      while ((pos = line.find("(reemplace)", pos)) != string::npos) {
        string class_name = argv[i];
        class_name[0] = toupper(class_name[0]);  // Pone la primera letra en mayúscula

        // Reemplaza guiones bajos por mayúsculas
        for (size_t j = 0; j < class_name.size(); j++) {
          if (class_name[j] == '_') {
            class_name.erase(j, 1);  // Borra el guion bajo
            class_name[j] = toupper(class_name[j]);  // Pone en mayúscula la letra siguiente
            j--;  // Ajusta el índice
          }
        }

        // Reemplaza "(reemplace)" por el nombre de la clase formateado
        line.replace(pos, 11, class_name);
        pos += class_name.size();  // Avanza el índice después del reemplazo
      }

      // Reemplazamos todas las ocurrencias de "{reemplace}" por argv[1] (nombre del archivo)
      pos = 0;
      while ((pos = line.find("{reemplace}", pos)) != string::npos) {
        line.replace(pos, 11, argv[1]);
        pos += string(argv[1]).size();  // Avanza el índice después del reemplazo
      }

      // Escribimos la línea completa, conservando los espacios iniciales
      output_files << line << '\n';
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
void CreateMain(char* argv[], const string& directory) {
  ofstream output_files;
  ifstream input_file;
  
  // Abrimos los archivos de entrada y salida
  input_file.open("main_file.txt", std::ios::in);
  output_files.open(directory + '/' + argv[1] + ".cc", std::ios::out);
  
  if (!input_file.is_open() || !output_files.is_open()) {
    cerr << "Error al abrir los archivos." << endl;
    return;
  }
  
  string line;
  
  // Leemos el archivo línea por línea
  while (getline(input_file, line)) {
    size_t pos = 0;

    // Reemplazamos todas las ocurrencias de "{reemplace}" por argv[1]
    while ((pos = line.find("{reemplace}", pos)) != string::npos) {
      line.replace(pos, 11, argv[1]);  // 11 es la longitud de "{reemplace}"
      pos += string(argv[1]).size();  // Avanzamos el índice después del reemplazo
    }
    
    // Escribimos la línea completa tal como es, incluyendo los espacios al inicio
    output_files << line << endl;
  }
  
  // Cerramos los archivos
  input_file.close();
  output_files.close();
}

/** @brief Shows correct usage of the program. 
  *        If the program wasn't run correctly, prints the
  *        help message.
  *
  * @param[in] argc Amount of arguments passed to the program
  * @param[in] argv Array of arguments
  */
void Usage(const int argc, char* argv[]) {
  if (argc == 2 && string(argv[1]) == "--help") {
    cerr << "Usage: " << argv[0] << " nombre, clases(opcional), directorio\n";
    cerr << "nombre: nombre del proyecto\n";
    cerr << "clases: nombre de las clases necesarias\n";
    cerr << "directorio: ruta donde se aloja el proyecto\n";
    exit(EXIT_FAILURE);
  } else if(argc < 2){
    cerr << "Modo de empleo: " << argv[0] << " nombre_proyecto, (nombre de las clases), directorio final\n";
    cerr << "Pruebe " << argv[0] << "--help para mas informacion.\n";
    exit(EXIT_FAILURE);
  }
}