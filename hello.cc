#include <iostream>

bool comprobacion(int condicion1, int condicion2) {
    // bool result_of_valor1_valor2{condicion1 == condicion2};

    if (condicion1 == condicion2) {
        std::cout << "true";
    } else{
        std::cout << "false";
    }
    return 0;
}

int main() {
   int valor1{0};
   int valor2{0}; 
   
   std::cout << "introduzca dos valores: " << std::endl;
   std::cin >> valor1 >> valor2;
    bool result_of_valor1_valor2{valor1 == valor2};
   std::cout << valor1 << " + " << valor2 << " = " << valor1 + valor2 << std::endl;

   std::cout << valor1 << " - " << valor2 << " = " << valor1 - valor2 << std::endl;

   std::cout << valor1 << " * " << valor2 << " = " << valor1 * valor2 << std::endl;

   std::cout << valor1 << " / " << valor2 << " = " << valor1 / valor2 << std::endl;

   std::cout << valor1 << " % " << valor2 << " = " << valor1 % valor2 << std::endl;

   std::cout << valor1 << " == " << valor2 << " = " << result_of_valor1_valor2 /* comprobacion(valor1, valor2) */ << std::endl;
   return 0;
}


