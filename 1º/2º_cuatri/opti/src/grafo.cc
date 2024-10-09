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
void MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred) {
  if (i != s) {
    MostrarCamino(s,pred[i],pred);
    cout << " -> " << i+1;
  } else
    cout << i+1;
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

void MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred) {
  if (i != s) {
    MostrarCamino(s,pred[i],pred);
    cout << " -> " << i+1;
  } else
    cout << i+1;
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
  vector<AristaPesada> aristas;
  aristas.resize(m);
  unsigned k{0};
  for (unsigned i = 0; i < n; i++) {
    for (unsigned j = 0; j < LS[i].size(); j++) {
      if (i < LS[i][j].j) {
        aristas[k].extremo1 = i;
        aristas[k].extremo2 = LS[i][j].j;
        aristas[k++].peso = LS[i][j].c;
      }
    }
  }
  unsigned head{0};
  unsigned cont{0};
  int pesoMST{0};

  vector<unsigned> root;
  root.resize(n);
  for (unsigned q = 0; q < n; q++) {
    root[q]=q;
  }

  do {
    for (unsigned i = head + 1; i < aristas.size(); i++) {
      if (aristas[head].peso > aristas[i].peso) {
        AristaPesada arista_head{aristas[head]};
        aristas[head] = aristas[i];
        aristas[i] = arista_head;
      }
    }
    if (root[aristas[head].extremo1] != root[aristas[head].extremo2]) {

      unsigned kill{root[aristas[head].extremo1]};
      for (unsigned i{0}; i < root.size(); i++) {
        if (root[i] == kill) {
          root[i] = root[aristas[head].extremo2];
        }
      }
      cont++;
      cout << "Arista número " << cont << " incorporada (" << aristas[head].extremo1 + 1 << ", " << aristas[head].extremo2 + 1
           << "), con peso " << aristas[head].peso << endl;
      pesoMST = pesoMST + aristas[head].peso;
    }
    head++;
  } while ((cont < (n - 1)) && (head < aristas.size()));
  if (cont == n - 1)
    cout << "El peso del arbol generador de mínimo coste es " << pesoMST << endl;
  else
    cout << "no existe arbol generador  ya que el grafo no es fuertemente conexo" << std::endl;
}

void GRAFO::PDM() {
  deque<unsigned> cola_doble;
  vector<int> d;
  vector<unsigned> pred;
  vector<bool> Encola;
  unsigned s;
  //Inicialmente no hay ningun nodo permanentemente etiquetado
  Encola.resize(n,false);
  //Inicialmente todas las etiquetas distancias son infinito
  d.resize(n,maxint);
  //Inicialmente el pred es null
  pred.resize(n,UERROR);
  // Pedimos por pantalla el nodo de partida s.
  do {
    cout << "El valor del nodo inicial [1-" << n << "]: ";
    cin >> s;
  } while (s == 0 || s > n);
  s--;
  //La etiqueta distancia del nodo s es 0, y es su propio pred
  d[s]=0; pred[s]=s;
  //añadimos s a cola_doble y actualizamos Encola
  cola_doble.push_back(s); Encola[s] = true;

  int min_cost{0};
  while (!cola_doble.empty()) {
    //quitamos el nodo k de la cola
    unsigned k = cola_doble.front(); 
    Encola[k] = false;
    cola_doble.pop_front();

    for (const auto &arco : LS[k]) {
      if (arco.c < min_cost) {
        min_cost = arco.c;
      }
      if (d[k] < static_cast<int>((n - 1)) * min_cost) {
        cout << "Existe al menos un circuito de coste negativo en el grafo" << endl;
        return;
      }
      if (d[arco.j] > d[k] + arco.c) {
        if (pred[arco.j] == UERROR) {
          cola_doble.push_back(arco.j);
        } else if (!Encola[arco.j]) {
          cola_doble.push_front(arco.j);
        }
        d[arco.j] = d[k] + arco.c;
        pred[arco.j] = k;
      }
    }
  }
  cout << "Soluciones: " << endl;
  for (unsigned i{0}; i < n; i++) {
    if (d[i] != maxint) {
      cout << "  Camino minimo para el nodo " << i + 1 << " con distancia " << d[i] <<  ": ";
      MostrarCamino(s, i, pred);
      cout << endl;
    } else {
      cout << "  Camino minimo para el nodo " << i + 1 << ": no existe\n";
    }
  }
}