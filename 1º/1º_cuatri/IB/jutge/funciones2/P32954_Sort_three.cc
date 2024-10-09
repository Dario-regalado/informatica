#include <iostream>

void sort3(int& a, int& b, int& c) {
  int temp{0};
  do {
    if (a > b) {
      temp = a;
      a = b;
      b = temp;
    }
    if (b > c) {
      temp = b;
      b = c;
      c = temp;
    }
  } while (a > b || b > c);
}

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << "sort3(" << a << ", " << b << ", " << c << ") → ";
  sort3(a, b, c);
  std::cout << a << " " << b << " " << c << std::endl;
}