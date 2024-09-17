#include <iostream>

int main() {
    int Temperatura{0};
    
    std::cin >> Temperatura;

    if (Temperatura < 10){
        std::cout << "it's cold" << std::endl;
        if (Temperatura <= 0){
            std::cout << "water would freeze" << std::endl;
        } 
    }
    else if (Temperatura >= 10 && Temperatura <= 30){
        std::cout << "it's ok" << std::endl;
    }
    else if (Temperatura > 30){
        std::cout << "it's hot" << std::endl;
        if (Temperatura >= 100){
            std::cout << "water would boil" << std::endl;
        }
    }            
    return 0;
}