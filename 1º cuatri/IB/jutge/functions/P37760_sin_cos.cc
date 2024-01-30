#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
  double degrees{0.0};
  while (std::cin >> degrees) {
    degrees *= (M_PI / 180);
    double sen{std::sin(degrees)};
    double cos{std::cos(degrees)};
    std::cout << std::fixed << std::setprecision(6) << sen << " " << cos << std::endl;
  }
}