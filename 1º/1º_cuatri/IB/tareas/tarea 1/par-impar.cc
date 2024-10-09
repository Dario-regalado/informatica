#include <iostream>

int main() {
    int numero{0};
    int resto{0};

    std::cout << "ingrese numero" << std::endl;
    std::cin >> numero;

    resto = numero % 2;
    
    if (resto == 0) {
        std::cout << numero << " es par" << std::endl;
    }
    else {
        std::cout << numero << " es impar" << std::endl;
    }    
    return 0;
}