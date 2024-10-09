#include <iostream>
#include "sll_t.h"
#include "matrix_t.hpp"
#include "sparse_vector_t.h"

using namespace std;
using namespace AED;

double TSD(matrix_t<double>& m, const int j = 1) {
  double suma = 0;
  if (j > m.get_m()) return suma;
  for (int i = j; i <= m.get_n(); i++) {
    suma += m.at(j, i);
  }
  return suma + TSD(m, j + 1);
}
double TSND(matrix_t<double>& m) {
  double suma =0;
  for (int i = 1; i <= m.get_m()-1; i++)
  {
    for (int j = i + 1; j <= m.get_n(); j++)
    {
      suma += m.at(i, j);
    }
  }
  return suma;
}
double TID(matrix_t<double>& m, const int i= 1) {
  double suma = 0.0;
  for (int j = 1; j <= i; j++)
    suma += m.at(i,j);
  if (i == m.get_m()) return suma;
  return suma + TID(m, i + 1);
}
double TIND(matrix_t<double>& m, const int i= 2) {
  double suma = 0;
  for (int j = 1; j < i; j++)
    suma += m.at(i,j);
  if (i == m.get_m()) return suma;
  return suma + TIND(m, i+1);
}

int bserach(const int* v, int i, int d, int x) {
  int c = -1;
  if (i > d) return c;
  if(v[i] == x) return i;
  else if(v[d] == x) return d;
  else return bserach(v, i+1, d-1, x);
}

int rsearch(const int* v, int i, int d, int x) {
  int c = -1;
  if (i <= d)
  { c = (i + d) / 2;
    if (v[c] != x)
    { const int  c1 = rsearch(v, i, c - 1, x);
      const int  c2 = rsearch(v, c + 1, d, x);
      c = max(c1, c2);
    }
  }
  return c;
}

void write(ostream& os, sll_node_t<int>* l) {
  while (l != NULL) {
    write(os, l->get_next());
    os << l->get_data();
  }
}

void fusion_asc(sll_t<int>& a, sll_t<int>&b, sll_t<int>& c) {
  sll_node_t<int>* aux1 = a.get_head();
  sll_node_t<int>* aux2 = b.get_head();
  while (aux1 != NULL && aux2 != NULL) {
    if(aux1->get_data() < aux2->get_data()) {

    }
  }

}

double scal_prod(const sparse_vector_t& s, vector_t<double>& b, const int i = 0) {
  double scal = 0;
  if (i >= s.get_nz()) return scal;
  scal = s.at(i).get_val() * b.at(s.at(i).get_inx());
  return scal + scal_prod(s, b, i + 1);
}

int main() {
  matrix_t<double> m;
  m.resize(5, 5);
  double x = 0;
  for (int i = 1; i <= 5; i++)
  {
    for (int j = 1; j <= 5; j++)
    {
      m.at(i, j) = x++;
    }
  }
  

  int* v = new int[20];
  for (int i = 0; i < 20; i++)
  {
    v[i] = rand() % 10;
    cout << v[i]<< " ";
  }
  
  cout << endl << rsearch(v, 0, 19, 4) << endl;
}