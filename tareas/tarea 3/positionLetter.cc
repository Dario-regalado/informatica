#include <iostream>
#include <string>

int letterPosition (const std::string& string1, char letra){
  for (int i = 0; i < string1.length(); i++ ){
    if (string1[i] == letra){
      return i;
    }
  }
  return -1;
}

int main(){
  std::string string_char{0};
  char character{0};
  std::cout << "introduzca la palabra a analizar: ";
  std::cin >> string_char;
  std::cout << "introduzca la letra: ";
  std::cin >> character;
  std::cout << letterPosition(string_char, character) << std::endl;
  return 0;
}