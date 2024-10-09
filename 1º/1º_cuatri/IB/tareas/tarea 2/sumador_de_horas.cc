#include <iostream>

int main() {
    int hora_actual{0};
    int cantidad_horas{0};

    std::cout << "Hora actual:" << std::endl;
    std::cin >> hora_actual;
    std::cout << "Cantidad de horas: " << std::endl;
    std::cin >> cantidad_horas;
    
    int hora_final{0};
    hora_final = (hora_actual + cantidad_horas) % 24;
    std::cout << "En " << cantidad_horas << " horas, el reloj marcara las " << hora_final << std::endl;
    return 0;
}