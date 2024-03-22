#include <iostream>

int main() {
    char letra_a_convertir{0};
   
    std::cin >> letra_a_convertir;
    if (islower(letra_a_convertir)){
        char letramayuscula = static_cast<char>(letra_a_convertir - 32);
        std::cout << letramayuscula << std::endl;
    } else if (isupper(letra_a_convertir)){
        char letraminuscula = static_cast<char>(letra_a_convertir + 32);
        std::cout << letraminuscula << std::endl;
    }    
    return 0;
}