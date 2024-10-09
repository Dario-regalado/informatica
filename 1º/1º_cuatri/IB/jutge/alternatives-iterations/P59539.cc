#include <iostream>
#include <iomanip>

int main() {
    int numero1{0};
    double suma_encadenada{0.0};

    std::cin >> numero1;
    for (int i = 1; i <= numero1; i++){
        suma_encadenada += (1.0 / i); 
    }
    std::cout << std::fixed << std::setprecision(4) << suma_encadenada << std::endl;
    return 0;
}