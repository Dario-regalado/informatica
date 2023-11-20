#include <iostream>
#include <vector>

class Calculator {
 public:
  using Number = int; /// this is a nested type alias

  Number Add(const Number summand1, const Number summand2) {
    auto result{summand1 + summand2};
    result_history_.push_back(result);
    return result;
  }

  void PrintHistory() {
    for (Number result : result_history_) {
      std::cout << result << " ";
    }
    std::cout << std::endl;
  }

 private:
  std::vector<Number> result_history_{};
};

int main() {
  Calculator calculator{};
  std::cout << calculator.Add(3, 4) << '\n'; // 7
  std::cout << calculator.Add(99, 24) << '\n'; // 123
  calculator.PrintHistory();
  return 0;
}