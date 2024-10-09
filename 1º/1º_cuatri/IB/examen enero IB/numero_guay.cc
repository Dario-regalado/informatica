#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::string numero{argv[1]};
    int suma = 0;

    for (int i = numero.length() - 1; i >= 0; i -= 2) {
        suma += numero[i] - '0';
    }
std::cout << suma << std::endl;
    if (suma % 2 == 0) {
        std::cout << numero << " es GUAY" << std::endl;
    } else {
        std::cout << numero << " no es GUAY" << std::endl;
    }

    return 0;
}