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

  // lee la secuencia
  for (int i = 0; i < n_estados_; i++) {
    Estado estado_actual;
    bool acpetacion;
    int n_transiciones;
    file >> estado_actual >> acpetacion >> n_transiciones;

		// si hay mas transiciones que simbolos en el alfabeto, no es un DFA
		if(alfabeto_.GetSize() < n_transiciones) is_dfa_ = false;
		
		// si el estado es de aceptacion, lo metemos en f_estados
    if(acpetacion) f_esstados_.Insert(estado_actual); 

		//introducimos el estado en q_estados
		q_estados_.Insert(estado_actual); 
		Estado antiguo_estado;
    for (int j = 0; j < n_transiciones; j++){
      Symbol simbolo_transicion;
			Estado estado__llegada;
			file >> simbolo_transicion >> estado__llegada;
			if(simbolo_transicion.GetSymbol() == '&') is_dfa_ = false;
			funcion_transicion_.AgregarTransicion(estado_actual, simbolo_transicion, estado__llegada);

			//comprobamos si hay mas de una transicion por simbolo
			if(estado__llegada == antiguo_estado) is_dfa_ = false;
			antiguo_estado = estado__llegada;
    }
  }
}


bool Automata::AnalizeWords(const std::string& input_word) { //que el metodo solo devuelva un true si la cadena es aceptada, lo del archivo de cadenas lo analizo en el main
  return funcion_transicion_.FuncTrans(input_word, q_estados_, f_esstados_, is_dfa_);
}