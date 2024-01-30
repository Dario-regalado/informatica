#include <iostream>

void print_line(char letter, std::string string, bool boolean) {
  std::cout << string << "('" << letter << "') = ";
    if (boolean == 1) {
      std::cout << "true" << std::endl;
    } else {
      std::cout << "false" << std::endl;
    }
}
bool letter (char caracter) {
  if (isalpha(caracter)) {
    return true;
  } else {
    return false;
  }
}

bool vowel(char caracter) {
  if (letter(caracter)) {
    caracter = tolower(caracter);
    if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u') {
      return true;
    } else {
      return false;
    }
  }
}

bool consonant (char caracter) {
  if (letter(caracter)) {
    if (!vowel(caracter)) {
      return true;
    }
  }
  return false;
}

bool upper(char caracter) {
  if (isupper(caracter)) {
    return true;
  } else {
    return false;
  }
}

bool lower(char caracter) {
  if (islower(caracter)) {
    return true;
  } else {
    return false;
  }
}

bool digit (char caracter) {
  if (isdigit(caracter)) {
    return true;
  } else {
    return false;
  }
}

int main() {
  char caracter;
  std::cin >> caracter;
  print_line(caracter, "letter", letter(caracter));
  print_line(caracter, "vowel", vowel(caracter));
  print_line(caracter, "consonant", consonant(caracter));
  print_line(caracter, "uppercase", upper(caracter));
  print_line(caracter, "lowercase", lower(caracter));
  print_line(caracter, "digit", digit(caracter));
  return 0; 

}