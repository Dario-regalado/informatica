
#include <iostream> // std::cout, std::endl


double MyFunc(int x = 7) {
  return 4.5;
}

std::string SayHello(const std::string& to_whom = "World ") {
 return "Hello " + to_whom + "!";
}

int main() {
  std::cout << SayHello() << std::endl;
  std::cout << SayHello("Students") << std::endl;
  return 0;
}