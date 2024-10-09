#include <iostream>

int main() {
    double valor1{0};
    double valor2{0};
    double valor3{0};
    double valor4{0};
    double media{0};

    std::cout << "Primer valor: ";
    std::cin >> valor1;

    std::cout << "Segundo valor: ";
    std::cin >> valor2;

    std::cout << "Tercer valor: ";
    std::cin >> valor3;

    std::cout << "introduzca el cuarto valor: ";
    std::cin >> valor4;

    media = (valor1 + valor2 + valor3 + valor4) / 4;

    std::cout << "el promedio es: " << media;
    return 0;
}