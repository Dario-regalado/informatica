#include <iostream>
#include <cmath>
#include <iomanip>

int main() {

    double polinomio{0}, numeroX{0}, total{0.0};
    int coefficient{0};
    std::cin >> numeroX;
    while (std::cin >> polinomio) {
        total = (polinomio * pow(numeroX,coefficient)) + total;
        coefficient++;
    }
    std::cout << std::fixed << std::setprecision(4) << total << std::endl;

    return 0;
}