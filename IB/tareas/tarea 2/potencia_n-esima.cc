#include <iostream>

int main() {
    int potencia{0};
    int coeficiente{2};
    int resultado{1};


    std::cout << "Introduzca numero: ";
    std::cin >> potencia;
    std::cout << "1 ";
    for (int i = 0; i < potencia; i++){
        resultado = resultado * coeficiente;
        std::cout << resultado << " ";
    }
    
    return 0;
}