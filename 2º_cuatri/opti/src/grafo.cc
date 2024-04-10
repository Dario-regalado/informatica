 /*
 *  GRAFO.CPP - Plantilla para la implementaci�n de la clase GRAFOS
 *
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos   : 2012-2021
 */

#include "grafo.h"
#include <algorithm>
#include <stack>
#include <sys/types.h>
#include <vector>

void GRAFO::destroy() {
  for (ulong i = 0; i < LS.size(); i++) {
    LS[i].clear();
    // A[i].clear();
    if (dirigido == 1) {
      LP[i].clear();
    };
  }
  LS.clear();
  LP.clear();
  // A.clear();
}

void GRAFO::build(char nombrefichero[85], int &errorapertura) {
  ElementoLista dummy;
  ifstream textfile;
  textfile.open(nombrefichero);
  if (textfile) {
    unsigned i, j, k;
    // leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
    textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
    // los nodos internamente se numeran desde 0 a n-1
    // creamos las n listas de sucesores
    LS.resize(n);
    if (dirigido)
      LP.resize(n);
    for (k=0;k<m;k++) {
      textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
      //damos los valores a dummy.j y dummy.c
      //situamos en la posici�n del nodo i a dummy mediante push_back
      //pendiente de hacer un segundo push_back si es no dirigido. O no.
      //pendiente la construccion de LP, si es dirigido
      //pendiente del valor a devolver en errorapertura
      //...
      // Lista de sucesores
      if (dirigido) {
        dummy.j = j - 1;
        LS[i - 1].emplace_back(dummy);
        // Lista de predecesores
        dummy.j = i - 1;
        LP[j - 1].emplace_back(dummy);
      } else {
        dummy.j = j - 1;
        LS[i - 1].emplace_back(dummy);
        // Lista de predecesores
        dummy.j = i - 1;
        LS[j - 1].emplace_back(dummy);
      }
    }
  } else {
    errorapertura = 1;
  }
}

GRAFO::~GRAFO()
{
  destroy();
}

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura) {
  build (nombrefichero, errorapertura);
}

void GRAFO::actualizar(char nombrefichero[85], int &errorapertura) {
  //Limpiamos la memoria dinamica asumida en la carga previa, como el destructor
  destroy();
  //Leemos del fichero y actualizamos G con nuevas LS y, en su caso, LP
  build(nombrefichero, errorapertura);
}

unsigned GRAFO::Es_dirigido() {
  return dirigido;
}

void GRAFO::Info_Grafo() {
  cout << "Numero de vertices: " << n << '\n';
  cout << "Numero de arcos: " << m << '\n';
  cout << "Grafo " << (dirigido ? "dirigido" : "no dirigido") << '\n';
}

void Mostrar_Lista(const vector<LA_nodo> &L) {
  for (ulong i{0}; i < L.size(); i++) {
    cout << i + 1 << ": ";
    for (ulong j{0}; j < L[i].size(); j++) {
      cout << "[" << L[i][j].j + 1 << ", " << L[i][j].c << "] ";
    }
    cout << '\n';
  }
}

void Mostrar_Lista(const vector<unsigned> &L, const ulong size) {
  for (ulong i{0}; i < size; i++) {
    if (i + 1 == size)
      cout << "[" << L[i] + 1 << "]";
    else
      cout << "[" << L[i] + 1 << "] -> ";
  }
  cout << '\n';
}

void GRAFO::Mostrar_Listas(int l) {
  if (l == 1) {
    Mostrar_Lista(LS);
  } else if (l == -1) {
    Mostrar_Lista(LP);
  }
}

// void GRAFO::Mostrar_Matriz() //Muestra la matriz de adyacencia, tanto los nodos adyacentes como sus costes
// {

// }

// Recorrido en profundidad recursivo con recorridos enum y postnum
void GRAFO::dfs_num(unsigned i, vector<LA_nodo>  L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) {
  visitado[i] = true;
  prenum[prenum_ind++]=i;//asignamos el orden de visita prenum que corresponde el nodo i
  for (unsigned j=0;j<L[i].size();j++) {
    if (!visitado[L[i][j].j]) {
      dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
    }
  }
  postnum[postnum_ind++]=i;//asignamos el orden de visita posnum que corresponde al nodo i
}

void GRAFO::RecorridoProfundidad() {
  vector<bool> visitado;
  vector<unsigned> prenum;
  vector<unsigned> postnum;
  unsigned prenum_ind{0};
  unsigned postnum_ind{0};

  visitado.resize(n, false);
  prenum.resize(n, 0);
  postnum.resize(n, 0);

  unsigned i;
  cout << "Recorrido de Profundidad\n";
  do {
    cout << "El valor del nodo inicial [1-" << n << "]: ";
    cin >> i;
  } while (i == 0 || i > n);

  dfs_num(i - 1, LS, visitado, prenum, prenum_ind, postnum, postnum_ind);
  cout << "Orden de visita de los nodos en preorden\n ";
  Mostrar_Lista(prenum, prenum_ind);
  cout << "Orden de visita de los nodos en postorden\n ";
  Mostrar_Lista(postnum, postnum_ind);
}

void GRAFO::bfs_num(	unsigned i, //nodo desde el que realizamos el recorrido en amplitud
        vector<LA_nodo>  L, //lista que recorremos, LS o LP; por defecto LS
        vector<bool> &visitado,
        vector<unsigned> &pred, //vector de predecesores en el recorrido
        vector<unsigned> &d) //vector de distancias a nodo i+1
//Recorrido en amplitud con la construcci�n de pred y d: usamos la cola
{
  visitado.resize(n, false);
  visitado[i] = true;

  pred.resize(n, 0); //creamos e inicializamos pred y d
  d.resize(n, 0);
  pred[i] = i;
  d[i] = 0;

  queue<unsigned> cola; //creamos e inicializamos la cola
  cola.push(i);//iniciamos el recorrido desde el nodo i+1

  // al menos entra una vez al visitar el nodo i+1 y continua hasta que la cola se vacie
  while (!cola.empty()) {
    unsigned k = cola.front(); //cogemos el nodo k+1 de la cola
    cola.pop();
    // lo sacamos de la cola
    // Hacemos el recorrido sobre L desde el nodo k+1
    for (unsigned j=0;j<L[k].size();j++) {
      //Recorremos todos los nodos u adyacentes al nodo k+1
      //Si el nodo u no esta visitado
      if (!visitado[L[k][j].j]) {
        //Lo visitamos
        visitado[L[k][j].j] = true;
        //Lo metemos en la cola
        cola.push(L[k][j].j);
        //le asignamos el predecesor
        pred[L[k][j].j] = k;
        //le calculamos su etiqueta distancia
        d[L[k][j].j] = d[k] + 1;
      }
    }
      //Hemos terminado pues la cola esta vacia
  }
}

// Construye un recorrido en amplitud desde un nodo inicial
void GRAFO::RecorridoAmplitud() {
  vector<bool> visitado;
  vector<unsigned> pred, d;
  unsigned start_node;
  cout << "Recorrido de Amplitud\n";
  do {
    cout << "El valor del nodo inicial [1-" << n << "]: ";
    cin >> start_node;
  } while (start_node == 0 || start_node > n);
  bfs_num(start_node - 1, LS, visitado, pred, d);
  cout << "\nNodos según distancia al nodo inicial en número de aristas\n";
  unsigned max_distance{*std::max_element(d.begin(), d.end())};
  for (ulong i{0}; i <= max_distance; i++) {
    cout << "Distancia " << i << " aristas";
    // Recorro cada elemento de la lista de distancias y compruebo si la distancia coincide, y si lo es, imprimo el nodo
    for (ulong j{0}; j < d.size(); j++) {
      if (i == d[j] && visitado[j]) {
        cout << ": " << j + 1 << ' ';
      }
    }
    cout << endl;
  }
  cout << endl;
  cout << "Ramas de conexión en el recorrido\n";
  for (unsigned i{0}; i < pred.size(); i++) {
    std::stack<unsigned> stack;
    unsigned last_node{i};
    for (unsigned j{0}; j < d[i]; j++) {
      stack.push(last_node);
      last_node = pred[last_node];
    }
    if (!stack.empty()) {
      stack.push(start_node - 1);
      while (!stack.empty()) {
        if (stack.size() == 1) {
          cout << stack.top() + 1 << endl;
        } else {
          cout << stack.top() + 1 << " - ";
        }
        stack.pop();
      }
    }
  }

}

void GRAFO::Kruskal() {
  vector <AristaPesada> Aristas;
  /*Cargamos todas las aristas de la lista de adyacencia*/
  Aristas.resize(m);
  unsigned k = 0;

  for (unsigned i = 0; i<n; i++) {
    for (unsigned j=0; j<LS[i].size();j++) {
      if (i < LS[i][j].j) {
        Aristas[k].extremo1 = i;
        Aristas[k].extremo2 = LS[i][j].j;
        Aristas[k++].peso = LS[i][j].c;
      }
    }
  };

  /*Inicializamos el registro de componentes conexas: cada nodo está en
  su componente conexa*/
  unsigned head = 0;
  unsigned cont = 0;
  int pesoMST = 0;

  vector <unsigned> Raiz;
  Raiz.resize(n);
  for (unsigned q = 0; q < n; q++) {
    Raiz[q]=q;
  };
  
  AristaPesada AristaTemp; //la usamos para el intercambio de aristas en el vector Aristas
  
  
}