#include <array>
#include <vector>
#include <iostream>

constexpr int pepe(void) {
    return 10;
}

int main() {
    std::array<int, 10> pepi;
    std::vector<int> pepa;
    const int i = pepe();
    std::cin >> i;
    constexpr int j = 10;
    constexpr int k = pepe();
}