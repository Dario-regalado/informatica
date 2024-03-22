#include <iostream>


void print(int s, char c, int n){
  std::string space{};
  for (int i = 0; i < s; i++) {
    space += ' ';
  }
  std::cout << space;
  for (int i = 0; i < n; i++) {
    std::cout << c;
  }
  std::cout << std::endl;
  
}

int main() {
  int s, n;
  char c;
  std::cin >> s >> c >> n;
  print(s, c, n);
}