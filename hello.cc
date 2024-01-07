
#include <iostream>
#include <iomanip>

int main(int argc, char** argv) {
  const double kPi{3.1415926535};
  const double kBig{123456789.0};
  const char kRet{'\n'};
  const char kSpace{' '};

  // default notation
  std::cout << kPi << kSpace << kBig << kRet;
  // fixed-point notation
  std::cout << std::fixed << kPi << kSpace << kBig << kRet;
  // scientific notation
  std::cout << std::scientific << kPi << kSpace << kBig << kRet;
  // fixed-point notation with 7 digits after decimal point
  std::cout << std::fixed << std::setprecision (7) << kPi << kSpace << kBig << kRet;
  // fixed-point notation with precision and width specified
  std::cout << std::setw(8) << std::fixed << std::setprecision(2) << kPi << kSpace << std::setw(20) << kBig << kRet;
  // fixed-point notation with precision, width, and fill specified
  std::cout << std::setw(8) << std::setfill('x') << std::fixed << std::setprecision(2) << kPi << kSpace << std::setw(20) << kBig << kRet;
  return 0;
}