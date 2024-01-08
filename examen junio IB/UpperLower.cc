#include <iostream>
#include <string>


void UpperLower(std::string& palabra_a_cambiar) {
  for (size_t i = 0; i < palabra_a_cambiar.length(); i++) {
    if (isupper(palabra_a_cambiar[i])){
      palabra_a_cambiar[i] = tolower(palabra_a_cambiar[i]);
    } else {
      palabra_a_cambiar[i] = toupper(palabra_a_cambiar[i]);
    } 
  }

}

int main(const int argc, char* argv[]) {
  std::string palabra_a_cambiar{argv[1]};
  std::string palabra_final{""};
  for (size_t i{0}; i < palabra_a_cambiar.length(); ++i) {
    char letra_a_cambiar{palabra_a_cambiar[i]};
    if (isupper(letra_a_cambiar)) {
      palabra_final += tolower(letra_a_cambiar);
    } else {
      palabra_final += toupper(letra_a_cambiar);
    }
  }
  UpperLower(palabra_a_cambiar);
  std::cout << palabra_final << " " << palabra_a_cambiar << std::endl;
  
}