/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date 
  * @brief 
  * @Practica 
  * @bug There are no known bugs
  * @file cya P02 automata_finito
  */

#include "Automata.h"


/**
 * @brief Construct a new Automata object
 * 
 * @param  
 */
Automata::Automata(std::ifstream& input_file) {
  AnalizeAutomata(input_file);
}
#include "automata.h"


void Automata::AnalizeAutomata(std::ifstream& file) {
    std::string line;

    // Leer la línea 1: Símbolos del alfabeto
    if (std::getline(file, line)) {
        std::istringstream symbols_stream(line);
        char symbol;
        while (symbols_stream >> symbol) {
            alfabeto_.Insert(symbol);  // Suponiendo que `Alphabet` tiene un método `AddSymbol`
        }
    }

    // Leer la línea 2: Número total de estados
    if (std::getline(file, line)) {
        std::istringstream states_stream(line);
        states_stream >> n_estados_;
    }

    // Leer la línea 3: Estado inicial
    if (std::getline(file, line)) {
        std::istringstream initial_state_stream(line);
        int initial_state_id;
        initial_state_stream >> initial_state_id;
        inicial_estado = Estado(initial_state_id);  // Suponiendo que `Estado` tiene un constructor que toma un ID
    }

    // Leer la información de cada estado
    for (int i = 0; i < n_estados_; ++i) {
        if (std::getline(file, line)) {
            std::istringstream state_stream(line);
            int state_id, is_accepting, num_transitions;
            state_stream >> state_id >> is_accepting >> num_transitions;

            // Crear el estado y establecer si es de aceptación
            Estado estado(state_id);
            if(is_accepting) f_esstados_.Insert(estado);

            // Leer las transiciones para este estado
            for (int j = 0; j < num_transitions; ++j) {
                char symbol;
                int target_state_id;
                state_stream >> symbol >> target_state_id;

                // Agregar la transición a la función de transición
                funcion_transicion_.AgregarTransicion(state_id, symbol, target_state_id);
                // Suponiendo que `FuncionT` tiene un método `AddTransition` que maneja el estado de origen, símbolo y destino.
            }

            // Añadir el estado a la colección de estados
            q_estados_.Insert(estado);
            // Si el estado es de aceptación, también añadirlo a la colección de estados de aceptación
            if (is_accepting == 1) {
                f_esstados_.Insert(estado);
            }
        }
    }
}


bool Automata::AnalizeWords(const std::string& input_word) { //que el metodo solo devuelva un true si la cadena es aceptada, lo del archivo de cadenas lo analizo en el main
  return funcion_transicion_.FuncTrans(input_word);
}