#include <iostream>

int main() {
    const double kFactor_conversion{2.54};
    double longitud{0};
    double resultado_conversion{0};

    std::cout << "introduzca longitud: ";
    std::cin >> longitud;

    resultado_conversion = longitud / kFactor_conversion;

    std::cout << longitud << " cm = " << resultado_conversion << " in";
    return 0;
}