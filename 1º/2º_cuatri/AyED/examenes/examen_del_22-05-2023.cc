
#include "sll_t.h"
#include "queue_l_t.h"
#include <iostream>

namespace stack
{
  template <class T>
class stack_sll_t {
 public:
  stack_sll_t(void);
  void Push(const T);
  void Pop();
  T Top();
  bool Empty();

 private:
  sll_t<T> pila_;
};

template <class T>
stack_sll_t<T>::stack_sll_t(void) {
  pila_(void);
}
template <class T>
void stack_sll_t<T>::Push(const T dato) {
  sll_node_t<T>* temp = new sll_node_t<T>(dato);
  pila_.insert_head(temp);
}

template <class T>
void stack_sll_t<T>::Pop() {
  delete pila_.head_;
}

template <class T>
T stack_sll_t<T>::Top() {
  return pila_.get_head()->get_data();
}
template <class T>
bool stack_sll_t<T>::Empty() {
  return pila_.get_head() == NULL   
}

} // namespace stack
using namespace stack;

int sumaElementos(stack::stack_sll_t<int>& p){
  int suma;
  if (p.Empty()) {
    return 0;
  } else {
    suma = p.Top();
    p.Pop();
    return suma + sumaElementos(p);
  }
}

void sll_union(const sll_t<int>& A, const sll_t<int>& B, sll_t<int>& C)
{
  sll_node_t<int>* aux = A.get_head();
  while (aux != NULL)
  {
    sll_node_t<int>* aux2 = B.get_head();
    bool equal = 0;
    while (aux2 != NULL)
    {
      if (aux->get_data() == aux2->get_data()) {
        equal = 1;
        break;
      }
      aux2 = aux2->get_next();
    }
    if (!equal)
    {
      C.push_front(aux);      
    }
    aux = aux->get_next();
    equal = 0;
  }

  // inserta todos los elementos de B
  aux = B.get_head();
  while (aux != NULL)
  {
    C.push_front(new sll_node_t<int>(aux->get_data()));
    aux = aux->get_next();
  }
}

void to_base(const unsigned n, const unsigned short b, queue_l_t<unsigned>& q){ 
  if (n >= b) {
    to_base(n / b, b, q);
    q.push(n % b);
  } else
    q.push(n);
}

block_t op1(const block_t A, const block_t B, const block t_C) {
  return ((A & B) | (B & t_C) | (t_C & A) & ~(A & (B & t_C)));
}

int main() {
  sll_t<int> A, B, C;
  A.push_front(new sll_node_t<int>(2));
  A.insert_after(A.get_head(), new sll_node_t<int>(3));
  A.insert_after(A.get_head(), new sll_node_t<int>(4));
  A.insert_after(A.get_head(), new sll_node_t<int>(1));

  B.push_front(new sll_node_t<int>(1));
  B.insert_after(B.get_head(), new sll_node_t<int>(6));
  B.insert_after(B.get_head(), new sll_node_t<int>(3));
  B.insert_after(B.get_head(), new sll_node_t<int>(5));

  sll_union(A, B, C);

  A.write(); std::cout << std::endl;
  B.write(); std::cout << std::endl;
  C.write(); std::cout << std::endl;
  
}