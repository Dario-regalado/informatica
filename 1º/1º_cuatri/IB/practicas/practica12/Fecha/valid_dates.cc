#include <iostream>

bool is_valid_date(int d, int m, int y) {
  if (d > 0 && d <= 31 && m > 0 && m <= 12 && y <= 9999 && y > 1800) {
    if ((y % 4 == 0 && y % 100 != 0 || y % 400 == 0) && d >= 29) {
      return true;
    } 
  } else{
    return false;
  }
}

int main() {
  std::cout << is_valid_date(29, 2, 2000) << std::endl;
  std::cout << is_valid_date(29, 2, 3000) << std::endl;
  std::cout << is_valid_date(-3, 14, 2000) << std::endl;
  std::cout << is_valid_date(1, -10, 1984) << std::endl;
}