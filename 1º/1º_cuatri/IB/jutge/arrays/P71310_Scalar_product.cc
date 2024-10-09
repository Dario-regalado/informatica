#include <vector>
#include <iostream>

double scalar_product(const std::vector<double>& u, const std::vector<double>& v) {
  double producto_escalar{};
  for (size_t i{0}; i < u.size(); ++i) {
    producto_escalar += (u[i] * v[i]);
  }
  return producto_escalar;
}
/*
int main() {
  int knumero_vectores;
  while (std::cin >> knumero_vectores) {
    std::vector<double> u(knumero_vectores);
    std::vector<double> v(knumero_vectores);
    for (int i = 0; i < knumero_vectores; ++i) {
      std::cin >> u[i];
    }
    for (int j = 0; j < knumero_vectores; ++j) {
      std::cin >> v[j];
    }
    std::cout << scalar_product(u, v) << std::endl;
  }
}*/