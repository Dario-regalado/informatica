#include <iostream>

int main() {
  std::string word{};
  std::string final_word{};
  while (std::cin >> word) {
    for (int i = word.length() - 1; i >= 0; --i) {
      final_word += word[i];
    }
    std::cout << final_word << std::endl;
    final_word.clear();
  }
  return 0;
} 
