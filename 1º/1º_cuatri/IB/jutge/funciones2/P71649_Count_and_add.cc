#include <iostream>


void count_and_add(int& num, int& sum) {
  int temp;
  num = 0;
  sum = 0;
  while (std::cin >> temp) {
    num++;
    sum += temp;
  }
}

