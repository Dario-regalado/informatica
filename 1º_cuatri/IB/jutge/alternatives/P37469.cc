#include <iostream>

int main() {
    int tiempoConvertir{0}, segundos{0}, minutos{0}, horas{0};

    std::cin >> tiempoConvertir;
    horas = tiempoConvertir / (3600);
    minutos = (tiempoConvertir % 3600) / 60;
    segundos = tiempoConvertir % 60;

    std::cout << horas << " " << minutos << " " << segundos << std::endl;
    return 0;
}