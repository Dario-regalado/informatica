#include <iostream>

int SequenceCount(int n_sequence) {
  int sequence{0};
  while (n_sequence != 1) {
    if (n_sequence % 2 == 0){
      n_sequence /= 2;
      ++sequence;
    } else if (n_sequence % 2 == 1) {
      n_sequence = n_sequence * 3 + 1;
      ++sequence;
    }
  }
  return sequence;
}

int main() {
  int n_sequence{0};
  while (std::cin >> n_sequence)
  std::cout << SequenceCount(n_sequence) << std::endl;

}