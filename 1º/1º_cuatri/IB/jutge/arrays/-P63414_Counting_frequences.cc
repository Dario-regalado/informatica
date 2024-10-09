#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> line{};
  int number_imputs{0};
  while (std::cin >> number_imputs) {
    for (int i = 0; i < number_imputs; i++) {
      int temp{0};
      std::cin >> temp;
      line.emplace_back(temp);
    }
  std::vector<int> result{};
  for (int i = 0; i < line.size(); i++){
    result.emplace_back(line[i]);
    if (result[i] == line[i]){}
  }
  
  }
}