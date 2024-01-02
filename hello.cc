#include <string>
#include <iostream>

class Student {
 public:
  Student(const std::string& name): name_{name} {}    // Constructor initializer list syntax (body is empty)
  std::string name() const { return name_; }          // Getter
 private:
  std::string name_{""};
};

void Print(const Student& student) {
  std::cout << "Student: " << student.name() << std::endl;
}

int main() {
  Student student{"Albert Einstein"};
  Print(student);
  return 0;
}