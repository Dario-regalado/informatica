#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

class Automata {
public:
    set<string> alfabeto;
    int numEstados;
    int estadoInicial;
    set<int> estadosAceptacion;
    map<int, map<string, set<int>>> transiciones;

    bool cargarDesdeArchivo(const string& archivo) {
        ifstream file(archivo);
        if (!file.is_open()) {
            cerr << "Error al abrir el archivo " << archivo << endl;
            return false;
        }

        string linea;
        // Leer el alfabeto
        getline(file, linea);
        istringstream ss(linea);
        string simbolo;
        while (ss >> simbolo) {
            if (simbolo == "&") {
                cerr << "Error: El carácter '&' no puede estar en el alfabeto." << endl;
                return false;
            }
            alfabeto.insert(simbolo);
        }

        // Leer el número de estados
        getline(file, linea);
        numEstados = stoi(linea);

        // Leer el estado inicial
        getline(file, linea);
        estadoInicial = stoi(linea);
        if (estadoInicial < 0 || estadoInicial >= numEstados) {
            cerr << "Error: El estado inicial no es válido." << endl;
            return false;
        }

        // Leer los estados y sus transiciones
        for (int i = 0; i < numEstados; ++i) {
            getline(file, linea);
            istringstream ss(linea);
            int estado, esAceptacion, numTransiciones;
            ss >> estado >> esAceptacion >> numTransiciones;

            if (esAceptacion == 1) {
                estadosAceptacion.insert(estado);
            }

            for (int j = 0; j < numTransiciones; ++j) {
                string simbolo;
                int destino;
                ss >> simbolo >> destino;

                if (alfabeto.find(simbolo) == alfabeto.end() && simbolo != "&") {
                    cerr << "Error: Símbolo " << simbolo << " no está en el alfabeto." << endl;
                    return false;
                }
                if (destino < 0 || destino >= numEstados) {
                    cerr << "Error: Estado destino " << destino << " no es válido." << endl;
                    return false;
                }

                transiciones[estado][simbolo].insert(destino);
            }
        }

        file.close();
        return true;
    }

    bool esDFA() const {
        for (const auto& [estado, trans] : transiciones) {
            for (const auto& [simbolo, destinos] : trans) {
                if (destinos.size() > 1) {
                    return false; // Hay múltiples destinos para un símbolo, es un NFA.
                }
            }
        }
        return true;
    }

    bool aceptarCadena(const string& cadena) const {
        if (esDFA()) {
            // Simular un DFA
            int estadoActual = estadoInicial;
            for (char c : cadena) {
                string simbolo(1, c);
                if (transiciones.at(estadoActual).find(simbolo) == transiciones.at(estadoActual).end()) {
                    return false; // No hay transición para el símbolo.
                }
                estadoActual = *transiciones.at(estadoActual).at(simbolo).begin();
            }
            return estadosAceptacion.find(estadoActual) != estadosAceptacion.end();
        } else {
            // Simular un NFA usando búsqueda DFS
            return simularNFA(estadoInicial, cadena, 0);
        }
    }

private:
    bool simularNFA(int estadoActual, const string& cadena, size_t posicion) const {
        if (posicion == cadena.size()) {
            return estadosAceptacion.find(estadoActual) != estadosAceptacion.end();
        }

        string simbolo(1, cadena[posicion]);

        // Intentar todas las transiciones posibles para el símbolo actual.
        if (transiciones.at(estadoActual).find(simbolo) != transiciones.at(estadoActual).end()) {
            for (int siguienteEstado : transiciones.at(estadoActual).at(simbolo)) {
                if (simularNFA(siguienteEstado, cadena, posicion + 1)) {
                    return true;
                }
            }
        }

        // Intentar transiciones con '&' (transiciones epsilon).
        if (transiciones.at(estadoActual).find("&") != transiciones.at(estadoActual).end()) {
            for (int siguienteEstado : transiciones.at(estadoActual).at("&")) {
                if (simularNFA(siguienteEstado, cadena, posicion)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <archivo_autómata.fa> <archivo_cadenas.txt>" << endl;
        return 1;
    }

    string archivoAutomata = argv[1];
    string archivoCadenas = argv[2];

    Automata automata;
    if (!automata.cargarDesdeArchivo(archivoAutomata)) {
        return 1; // Error al cargar el autómata.
    }

    ifstream fileCadenas(archivoCadenas);
    if (!fileCadenas.is_open()) {
        cerr << "Error al abrir el archivo " << archivoCadenas << endl;
        return 1;
    }

    string linea;
    while (getline(fileCadenas, linea)) {
        istringstream ss(linea);
        int numero;
        string cadena;
        ss >> numero >> cadena;

        bool aceptada = automata.aceptarCadena(cadena);
        cout << numero << " " << cadena << " --- " << (aceptada ? "Accepted" : "Rejected") << endl;
    }

    fileCadenas.close();
    return 0;
}
