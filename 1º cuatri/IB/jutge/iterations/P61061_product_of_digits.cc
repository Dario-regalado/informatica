#include <iostream>

int main() {
  int imput_number{0};

  while (std::cin >> imput_number) {
    if (imput_number < 10){
      std::cout << "The product of the digits of " << imput_number << " is " << imput_number << "." << std::endl;
    }
    while (imput_number >= 10) {
    int numero_respuesto{imput_number};
    int temp{1};
    while (imput_number != 0) {
      temp *= imput_number % 10;
      imput_number /= 10;
    }
    std::cout << "The product of the digits of " << numero_respuesto << " is " << temp << "." << std::endl;
    imput_number = temp;
    }
    std::cout << "----------" << std::endl;
  }
  
  return 0;
}