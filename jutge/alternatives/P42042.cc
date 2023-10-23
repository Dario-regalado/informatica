#include <iostream>

int main() {
    char letra;

    std::cin >> letra;

    if (islower(letra)){
        std::cout << "lowercase" << std::endl;
    }
    else if (isupper(letra)){
        std::cout << "uppercase" << std::endl;
    }

    char lowercaseLetter = tolower(letra); // Convert to lowercase for vowel check
    char condicion;
    condicion = lowercaseLetter == 'a' || lowercaseLetter == 'e' || lowercaseLetter == 'i' || lowercaseLetter == 'o' || lowercaseLetter == 'u';
    if (letra = condicion){
            std::cout << "vowel" << std::endl;
        } else{
            std::cout << "consonant" << std::endl;
        }    
    return 0;
}