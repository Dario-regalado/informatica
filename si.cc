#include <iostream>
#include <regex>
#include <string>

int main() {
    std::regex expresion = std::regex(("\\s+(int|double).*?\\;"));
    std::string prueba("    int factorial = 1;");
    std::smatch matches;
    std::regex_search(prueba, matches, expresion);
    for (auto element : matches)
        std::cout << element << std::endl;
}