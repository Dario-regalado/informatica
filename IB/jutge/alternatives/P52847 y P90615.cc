#include <iostream>

int main() {
    int numero1{0}; 
    int numero2{0}; 
    int numero3{0};

    std::cin >> numero1 >> numero2 >> numero3;
    int numeroMayor{numero1};
    if (numero2 > numeroMayor){
        numeroMayor = numero2;
    }
    else if (numero3 > numeroMayor){
        numeroMayor = numero3;
    }
    std::cout << numeroMayor << std::endl;
    return 0;
}