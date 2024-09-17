/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2023-2024
  *
  * @author  Dario Regalado Gonzalez alu0101640150@ull.edu.es
  * @date Nov 23 2023
  * @brief 
  * @bug There are no known bugs
  * @see
  */

#include "dependencies.h"

std::string CountVowels (const std::string& filename) {
  std::ifstream file;
  file.open(filename);
  if (file.is_open()) {
    std::string word{};
    std::string return_word{};
    while (file >> word) { 
      int temp{0};
      for (int i = 0; i < word.length(); ++i) { //iterate in every word of the file
        int count_vowels{0};
        tolower(word[i]); //count the vowels of the word
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
          ++count_vowels;
        }
        if (temp < count_vowels) { //check if new word has more vowels than the last bigger word
          temp = count_vowels;
          return_word = word;
        }
        
      }
      
    }
    
    
  }
  
  
}