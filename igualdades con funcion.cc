#include <iostream>

void comprobacion(int condicion1, int condicion2, std::string& result) {
    if (condicion1 == condicion2) {
        result = "true";
    } else{
        result = "false";
    }
    return;
}

int main() {
   int valor1{0};
   int valor2{0}; 
   
   std::cout << "introduzca dos valores: " << std::endl;
   std::cin >> valor1 >> valor2;
    std::string result_of_valor1_valor2{0};
   std::cout << valor1 << " + " << valor2 << " = " << valor1 + valor2 << std::endl;

   std::cout << valor1 << " - " << valor2 << " = " << valor1 - valor2 << std::endl;

   std::cout << valor1 << " * " << valor2 << " = " << valor1 * valor2 << std::endl;

   std::cout << valor1 << " / " << valor2 << " = " << valor1 / valor2 << std::endl;

   std::cout << valor1 << " % " << valor2 << " = " << valor1 % valor2 << std::endl;

   comprobacion(valor1, valor2, result_of_valor1_valor2);

   std::cout << valor1 << " == " << valor2 << " = " << result_of_valor1_valor2 << std::endl;
   /* if (valor1 == valor2) {
        std::cout << "true\n";
    } else {
        std::cout << "false" << std::endl;
    }
    */
   return 0;
}


