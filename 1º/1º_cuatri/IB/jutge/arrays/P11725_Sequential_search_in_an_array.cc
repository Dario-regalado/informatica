#include <iostream>
#include <vector>

bool exists(int x, const std::vector<int>& v){
  for (int i{0}; i < v.size(); ++i){
    if (x == v[i]) {
      return true;
    } 
  } return false;
}

int main() {
  int numero{4};
  std::vector<int> vector{'1', '2', '3', '4'};
  std::cout << exists(numero, vector) << std::endl;
  return 0;
}
