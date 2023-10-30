#include <iostream>
#include <string>

int countvowels (const std::string& string1){
  int count{0};
  for (char palabra : string1){
    char lowerCase = tolower(palabra);
    if (palabra == 'a' || palabra == 'e' || palabra == 'i'|| palabra == 'o'|| palabra == 'u'){
      count++;
    }
  }
  return count;
}

int main(){
  std::string string1{0};
  std::cout << "introduzca la palabra a analizar: ";
  std::getline(std::cin, string1);
  std::cout << "el numero de vocales es; " << countvowels(string1) << std::endl;
  return 0;
}