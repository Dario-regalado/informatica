#include <iostream>
#include <fstream>
#include <cmath> // Para la función M_PI que representa el valor de pi


int main() {
    double radio_circunferencia{0};
    std::ifstream InputFile("entrada.txt");

    InputFile >> radio_circunferencia;

    std::cout << "el perimetro es: " << 2 * M_PI * radio_circunferencia << std::endl;
    std::cout << "el area es: " << M_PI * radio_circunferencia * radio_circunferencia << std::endl;
    return 0;
}