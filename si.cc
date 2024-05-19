#include <iostream>
int grid[3][3] = {{1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9}};

int main() {
  while (true){

    for (int row = 0; row < 3; row++)
    {
      for (int col = 0; col < 3; col++)
      {
        std::cout << grid[row][col];
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
  }
  
}