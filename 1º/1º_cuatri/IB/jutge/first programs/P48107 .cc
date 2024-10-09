#include <iostream>

int main() {
    int divisor{0}, dividendo{0};

    std::cin >> divisor >> dividendo; 

    while (dividendo < 0) {
        return 1;
    }

    std::cout << divisor / dividendo << " " << divisor % dividendo << std::endl;
    return 0;
}