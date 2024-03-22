#include <iostream>
#include <string>

int main() {
  std::string parentheses{0};
  int open_paren{0};
  int closed_paren{0};

  std::cin >> parentheses;
  for (int i = 0; i < parentheses.length(); i++){
    if (parentheses[i] == '('){
      open_paren++;
    } else if (parentheses[i] == ')'){
      closed_paren++;
    } 
    if (open_paren < closed_paren){
      break;
    }
    
  }
  if (open_paren == closed_paren){
      std::cout << "yes" << std::endl;
  } else{
      std::cout << "no" << std::endl;
  }
  return 0;
}