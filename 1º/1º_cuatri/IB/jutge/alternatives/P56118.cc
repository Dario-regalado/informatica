#include <iostream>

int main() {
    int numero1{0}, numero2{0};
    std::cin >> numero1 >> numero2;
    if (numero1 < numero2){
        std::cout << numero2 << std::endl;
    } else {
        std::cout << numero1 << std::endl;
    }
    
    return 0;
}