// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase TAD cola implementada con una lista

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cassert>

#include "dll_t.h"

// Clase TAD cola implementada con una lista
template <class T> class queue_l_t {
 private:
  dll_t<T>    l_;

 public:
  // constructor
  queue_l_t(void) : l_() {}

  // destructor
  ~queue_l_t(void) {}

  // operaciones
  bool empty(void) const;
  int size(void) const;
  void push(const T& dato);
  void pop(void);
  const T& front(void) const;
  const T& back(void) const;

  void mov_2_elemments();
  void multiplicate (int n);
  queue_l_t<T> RemoveImpar();
  void move(int n);

  // E/S
  std::ostream& write(std::ostream& os = std::cout) const;
};


// operaciones
template<class T> bool queue_l_t<T>::empty(void) const {
  return l_.empty();
}

template<class T> int queue_l_t<T>::size(void) const {
  return l_.get_size();	
}

template<class T> void queue_l_t<T>::push(const T& dato) {
  dll_node_t<T>* node = new dll_node_t<T>(dato);
  assert(node != NULL);
  l_.push_front(node);
}

template<class T> void queue_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_back();
}

template<class T> const T& queue_l_t<T>::front(void) const {
  assert(!empty());
  return (l_.get_tail()->get_data());
}

template<class T> const T& queue_l_t<T>::back(void) const {
  assert(!empty());
  return (l_.get_head()->get_data());
}

 // E/S
template<class T> std::ostream& queue_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) {
    os << aux->get_data() << " ";
    aux = aux->get_next();
  }
  os << std::endl;
  return os;
}

template<class T> std::ostream& operator<<(std::ostream& os,
					   const queue_l_t<T>& q) {
  q.write(os);
  return os;
}

template <class T>
void 
queue_l_t<T>::mov_2_elemments(void){
	for (int i = 0; i < 2; i++) {	
	T first = front();
	push(first);
	pop();
	}
}

template <class T>
void
queue_l_t<T>::multiplicate(int n) {
  int tamaño = size();
  for (int i = 0; i < tamaño; i++) {
    T first = front();
    for (int i = 0; i < n; i++) {
      push(first);
    }
    pop();
  }
}


template <class T>
queue_l_t<T>
queue_l_t<T>::RemoveImpar(){
  queue_l_t<T> cola_retorno;
  while (!empty())
  {
  pop();
  cola_retorno.push(front());
  pop();
  }
  return cola_retorno;
}

template <class T>
void
queue_l_t<T>::move(int n) {
  queue_l_t<T> first, second;
  for (int i = 0; i < n; i++) {
    first.push(front());
    pop();
  }
  first.write();
  std::cout << '\n';

  while (!empty()){
    second.push(front());
    pop();
  }
  second.write();
  std::cout << '\n';

}

#endif  // QUEUE_H_
