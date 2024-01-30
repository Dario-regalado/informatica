#include <iostream>
#include <vector>
#include <string>

int main() {
  std::vector<std::string> input_word{};
  std::string emplace_input{};
  int result{0};
  getline(std::cin, emplace_input);
  for (int i{0}; i < emplace_input.length(); ++i) {
    input_word.emplace_back(emplace_input[i]);
    std::cout << emplace_input << std::endl;
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
  std::cout << result << std::endl; 
  return result;
}