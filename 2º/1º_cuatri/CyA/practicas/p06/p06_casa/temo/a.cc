#include <iostream>
#include "QEstados.h"
#include "FEstados.h"
#include "funcion_t.h"

int main() {
    // Crear estados y el autómata
    QEstados estados;
    estados.Insert(Estado(0));
    estados.Insert(Estado(1));
    estados.Insert(Estado(2));

    FEstados finales = {Estado(2)};

    FuncionT ft(estados, finales);
    ft.AgregarTransicion(Estado(0), 'a', Estado(1));
    ft.AgregarTransicion(Estado(1), 'b', Estado(2));
    ft.AgregarTransicion(Estado(1), '&', Estado(2)); // Ejemplo de transición epsilon

    // Probar con una cadena de entrada
    std::string input = "ab";
    ft.FuncTrans(input);
    std::cout << input << " --- "; 
    ft.StringAccepted()? std::cout << "Accepted\n" : std::cout << "Rejected\n";

    return 0;
}