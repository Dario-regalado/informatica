#include <iostream>

int main() {
    int secuencia{0};
    int valor1{0};
    int valor2{1};

    std::cout << "introduzca la cantidad de numeros de la secuencia de Fibonacci: " << std::endl;
    std::cin >> secuencia;
    for (int i = 0; i < secuencia; i++){
        int temp{valor1};

        valor1 = valor2;
        valor2 = temp + valor2;
        std::cout << valor1 << " ";
    }
    
    return 0;
}