#include <iostream>
#include <vector>
#include <string>

int main() {
  std::vector<std::string> input_word{};
  std::string emplace_input{};
  int result{0};

  while (std::cin >> emplace_input) {
    input_word.emplace_back(emplace_input);
  }
  int start, end;
  for (int i{0}; i < input_word.size(); ++i) {
    if (input_word[i] == "beginning") {
      start = i;
    }
    if (input_word[i] == "end") {
      end = i;
    }
    
    result = end - start;
  }  
  return result;
}