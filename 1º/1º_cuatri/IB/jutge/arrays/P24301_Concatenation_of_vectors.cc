#include <vector>
#include <iostream>

std::vector<int> concatenation(const std::vector<int>& v1, const std::vector<int>& v2) {
  std::vector<int> final_vector{};
  for (auto& element : v1) {
    final_vector.emplace_back(element);
  }
  for (auto &element : v2) {
    final_vector.emplace_back(element);
  }
  return final_vector;
}

int main() {
  std::vector<int> v1{1, 2, 3}, v2{4, 5, 6}, final = concatenation(v1, v2);
  for (auto &element : final) {
    std::cout << element << " ";
  }
  return 0;
}