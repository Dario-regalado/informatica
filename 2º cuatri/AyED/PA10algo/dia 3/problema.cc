/**
 * @file problema.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>

using namespace std;

int main() {

  const int m=3;
  int C[m][m] = {{5, 1, 3},
                  {-1, 8, 2},
                  {-3, -2, 5}};
  
  bool is_sym = true;
  for (int i = 1; is_sym && (i < m); i++) {
    for (int j = 0; is_sym && (j <= i - 1); j++) {
      if (C[i][j] != -C[j][i])
        is_sym = false;
    }
  }
  cout << (is_sym ? "true" : "false") << endl;

  return 0;
}

double scalar_product(const sv1&, const sv2&) {
  double producto = 0;
  for (int i = 0; i < min(sv1.nz_, sv2.nz_); i++) {
    producto += sv1.val_[];
  }
  
}