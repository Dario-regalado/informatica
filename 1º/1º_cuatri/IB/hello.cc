#include <iostream>
void Sum(int value_a, int& value_b, int& value_c) {
value_a = value_b + value_c;
value_b = value_a + value_c;
value_c = value_a + value_b;
}
int main() {
int first{2}, second{3};
Sum(first, second, second);
std::cout << first << " " << second;
return 0;
}
