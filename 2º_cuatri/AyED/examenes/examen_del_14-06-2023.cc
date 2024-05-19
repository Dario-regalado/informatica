#include <iostream>
#include <string>
#include "vector_t.h"
#include "stack_l_t.h"

using namespace std;

vector_t<int> rotate(const vector_t<int>& v, const int r) {
  vector_t<int> temp(v.get_size());
  for (int i = 0, j=0; i < v.get_size(); i++)
  {
    if (i + r - 1 < v.get_size())
    {
      temp[i] = v[i+r-1];
    } else {
      temp[i] = v[j];
      ++j;
    }
  } 
  return temp;
}

bool es_palindroma(const vector_t<char>& cadena) {
  int n = cadena.get_size() / 2;
  stack_l_t<char> pila;
  for (int i = 0; i < n; i++)
  {
    pila.push(cadena[i]);
  }
  cadena.get_size() % 2 == 1 ? n = n+1 : n = n;
  bool palin = 1;
  for (int i = n; i < cadena.get_size() && palin; i++)
  {
    if (cadena[i] != pila.top()) palin = 0;
    pila.pop();
  }
  return palin;
}

void all_bin(vector_t<char>& binario, const int i = 0) {
  if(i == binario.get_size()) cout << binario << " ";
  else
    for (int j = 0; j < 1; j++) {
      binario[i] = static_cast<char>(j);
      all_bin(binario, i + 1);
    }
}

dll_node_t<int>* find(const int v) {
  dll_node_t<int>* aux; //= get_head();
  while (aux != NULL) {
    if (aux->get_data() == v) return aux;
    aux = aux->get_next();
  }
  return NULL;
}

void erase_evens(void) {
  dll_node_t<int>* aux; // = get_head();
  while (aux != NULL && aux->get_next() != NULL) {
    // delete erase_after(aux);
    aux = aux->get_next();
  }
}

double ackerman (int x, int y) {
  if (x == 0) return y + 1;
  else if (y == 0) return ackerman(x-1, 1);
  else return ackerman(x-1, ackerman(x, y-1));
}

int main () {
  vector_t<int> v(9);
  vector_t<char> palin(11);
  v.at(0) = 10; v.at(1) = 21; v.at(2) = 32; v.at(3) = 43;v.at(4) = 54; v.at(5) = 65; v.at(6) = 76; v.at(7) = 87; v.at(8) = 98;
  vector_t<int> temp = rotate(v, 5);
  temp.write();
  
  std::string palind = "YOHAGOYOGAHOY";
  for (int i = 0; i < palin.get_size(); i++)
    palin[i] = palind[i];
  es_palindroma(palin) ? std::cout << "es palindorma\n" : std::cout << "no es palindroma\n";
  
}