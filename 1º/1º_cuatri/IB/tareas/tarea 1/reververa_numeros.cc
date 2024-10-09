#include <iostream>

int main() {
    int numero{0};

    std::cout << "intrduce el numero" << std::endl;
    std::cin >> numero;

    if (numero >= 100 && numero <= 999) {
        int numero1 = numero % 10;
        int numero2 = (numero / 10) % 10;
        int numero3 = numero / 100;

        std::cout << "tu numero al reves es: " << numero1 << numero2 << numero3 << std:: endl;
    } else {
        std::cout << "el numero no tiene 3 digitos" << std::endl;
    }
    return 0;
}