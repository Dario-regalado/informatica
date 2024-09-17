#include <iostream>

int main() {
    int numero_de_divisores{0};

    std::cout << "introduzca numero: " << std::endl;
    std::cin >> numero_de_divisores;

    for (int i = 1; i <= numero_de_divisores; i++){
        if (numero_de_divisores % i == 0){
            std::cout << i << " ";
        }
    }       
    return 0;
}