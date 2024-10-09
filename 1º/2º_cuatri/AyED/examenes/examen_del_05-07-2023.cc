#include <iostream>
#include <vector>
#include <string>
#include "dll_t.h"
#include "sparse_vector_t.h"
#include "matrix_t.hpp"
using namespace std;
using namespace AED;

double operator*(const sparse_vector_t& a, const sparse_vector_t& b) {
  double suma = 0;
  assert(a.get_n() == b.get_n());
  int i = 0, j = 0;
  while (i < a.get_nz() && j < b.get_nz())
  {
    if (a[i].get_inx() == b[j].get_inx())
    {
      suma += a[i].get_val() * b[i].get_val();
      i++; j++;
    } else if (a[i].get_inx() < b[i].get_inx()) {
      i++;
    } else {
      j++;
    }
  }
  return suma;
}

void hacking(vector<char>& pw, const int i = 0) {
const char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int ALPHABET_size = (int)sizeof(ALPHABET) - 1;
  if (i == pw.size())
    for (auto &element : pw) cout << element << " ";
  else {
    for (int j = 0; j < ALPHABET_size; ++j) {
      pw[i] == ALPHABET[j];
      hacking(pw, i + 1);
    }
  }
}

bool is_estocastica(matrix_t<int> m, int j = 1) {
  assert(m.get_m() == m.get_n());
  if (j > m.get_n()) return false;
  int suma = 0;
  for (int i = 1; i <= m.get_m(); i++)
  {
    if(m.at(i, j) < 0) return false;
    suma += m.at(i, j);
  }
  if (suma != 1) return false;
  if (j == m.get_n()) return true;
  return is_estocastica(m, j + 1);
}

bool is_palindrome(const vector_t<char>& s, const int i, const int d) {
  if (i >= d) return true;
  bool palin;
  palin = s[i] == s[d];
  return (palin && is_palindrome(s, i+1, d-1));
}

void merge(dll_t<int>& L1, dll_t<int>& L2, dll_t<int>& R) {
  dll_node_t<int>* aux1 = L1.get_head();
  dll_node_t<int>* aux2 = L2.get_head();
  while (aux1 != NULL && aux2 != NULL) {
    if (aux1->get_data() < aux2->get_data()) {
      R.push_back(new dll_node_t<int>(aux1->get_data()));
      aux1 = aux1->get_next();
    } else if (aux1->get_data() > aux2->get_data()) {
      R.push_back(new dll_node_t<int>(aux2->get_data()));
      aux2 = aux2->get_next();
    } else {
      R.push_back(new dll_node_t<int>(aux2->get_data()));
      aux1 = aux1->get_next();
      aux2 = aux2->get_next();
    }
    while (aux1 != NULL) {
      R.push_back(new dll_node_t<int>(aux1->get_data()));
      aux1 = aux1->get_next();
    }
    while (aux2 != NULL) {
      R.push_back(new dll_node_t<int>(aux2->get_data()));
      aux2 = aux2->get_next();
    }
  }
}

int main() {
  matrix_t<int> m;
  m.resize(3,3);
  for (int i = 1; i <= m.get_m(); i++)
  {
    for (int j = 1; j <= m.get_n(); j++)
    {
      m.at(i, j) = 0;
    }
  }
  m.at(1, 1) = 1;
  m.at(3, 3) = 1;
  m.at(1, 3) = 1;
  m.at(2, 2) = 1;
  is_estocastica(m) ? cout << "es estocastica\n" : cout << "no es estocastica\n";

  string palind = "YOHAGOYOGAHOY";
}