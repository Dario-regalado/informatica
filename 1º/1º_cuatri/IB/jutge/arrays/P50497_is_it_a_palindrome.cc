#include <iostream>

bool is_palindrome(const std::string& si) {
  std::string s{si};
  std::string temp{""};
  for (size_t i = 0; i < s.length(); i++) {
   s[i] = tolower(s[i]); 
  }
  for (size_t i{s.length()}; i > 0; --i) {
    temp += s[i - 1];
  }
  return temp == s;
}


int main(const int argc, char* argv[]) {
  std::string palabra{argv[1]};
  if (is_palindrome(palabra) == 1) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }
  return 0;  
}