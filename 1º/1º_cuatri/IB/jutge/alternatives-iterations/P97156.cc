#include <iostream>

int main() {
    int numero1{0};
    int numero2{0};
    
    std::cin >> numero1 >> numero2;
    int intervalo = numero2 - numero1;
    if (numero2 < numero1){
        std::cout << std::endl;
        return 0;
    }
    for (int i = 0; i < intervalo; i++){
        std::cout << numero1 << ",";
        ++numero1;
    }
    std::cout << numero2 << std::endl;
    return 0;
}