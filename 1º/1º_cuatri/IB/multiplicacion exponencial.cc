#include <iostream>

int main() {
    int potencia(0);
    int numero(0);
    int result{1};

    std::cout << "ingrese numero " << std::endl;
    std::cin >> numero;

    std::cout << "ingrese exponente " << std::endl;
    std::cin >> potencia;

    for (int i = 0; i < potencia; i++) {
        result = result * numero;
    }
    std::cout << result << std::endl;
    return 0;  

}