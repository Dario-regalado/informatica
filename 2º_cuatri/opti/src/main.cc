 /*
 *  Programa principal.
 *
 *
 *               Autores : Antonio Sedeno Noda, Sergio Alonso.
 *               Cursos  : 2012-2021
 */

#include <iostream>
#include <limits>
#include <string.h>
#include "grafo.h"

void clrscr() {
  cout << "\033[2J\033[H";
}

void pressanykey() {
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  cin.get();
}

//Expresion del menu de opciones segun sea un grafo dirigido o no dirigido
void menu (unsigned dirigido, char &opcion) {
  cout << "Optimizacion en Grafos, 2023-2024 DARIO REGALADO" << endl;
  cout << "c. [c]argar grafo desde fichero" << endl;
  cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
  if (dirigido == 0) {
    cout << "a. Mostrar la lista de [a]dyacencia del grafo" << endl;
    cout << "y. Mostrar la matriz de ad[y]acencia del grafo" << endl;
    cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo" << endl;
    cout << "r. Realizar un recorrido en p[r]ofundidad del grafo desde un nodo" << endl;
    cout << "o. Mostrar c[o]mponentes conexas del grafo" << endl;
    cout << "k. Mostrar arbol generador minimo coste, [k]ruskal" << endl;
    cout << "p. Mostrar arbol generador minimo coste, [p]rim" << endl;

  } else {
    cout << "s. Mostrar la lista de [s]ucesores del grafo" << endl;
    cout << "e. Mostrar la lista de pr[e]decesores del grafo" << endl;
    cout << "y. Mostrar la matriz de ad[y]acencia del grafo" << endl;
    cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo por sucesores" << endl;
    cout << "r. Realizar un recorrido en p[r]ofundidad del grafo desde un nodo por sucesores" << endl;
    cout << "d. Caminos minimos: [d]ijkstra" << endl;
    cout << "v. Caminos minimos: Comparamos Dijkstra [v]s BellmanFordEnd" << endl;
    cout << "x. Caminos minimos: Modificacion de Pape y Dsopo" << endl;
    cout << "f. Caminos minimos: [f]loyd-warshall" << endl;
  };

  cout << "q. Finalizar el programa" << endl;
  cout << "Introduce la letra de la accion a ejecutar  > ";
  cin >> opcion;
};


// El principal es simplemente un gestor de menu, diferenciando acciones para dirigido y para no dirigido, y un menu inicial si no hay un grafo cargado
int main(int argc, char *argv[]) {
  int error_apertura;
  char nombrefichero[85], opcion;
  clrscr();
  //Si tenemos el nombre del primer fichero por argumento, es una excepcion, y lo intentamos cargar, si no, lo pedimos desde teclado
  if (argc > 1) {
    cout << "Cargando datos desde el fichero dado como argumento" << endl;
    strcpy(nombrefichero, argv[1]);
  } else {
    cout << "Introduce el nombre completo del fichero de datos" << endl;
    cin >> nombrefichero;
  };
  GRAFO G(nombrefichero, error_apertura);
  if (error_apertura == 1) {
    cout << "Error en la apertura del fichero desde argumento: revisa nombre y formato" << endl;
    pressanykey();
    clrscr();
  } else {
    cout<< "Grafo cargado desde el fichero " << nombrefichero << endl;
    pressanykey();
    clrscr();
    do {
      clrscr();
      menu(G.Es_dirigido(), opcion);
      clrscr();
      switch (opcion) {
        case 'c' :
          cout << "Introduce el nombre completo del fichero de datos" << endl;
          cin >> nombrefichero;
          G.actualizar(nombrefichero, error_apertura);
          if (error_apertura == 1) {
            cout << "Error en la apertura del fichero: revisa nombre y formato : puedes volver a intentarlo" << endl;
          } else {
            cout << "Fichero cargado correctamente desde " << nombrefichero << endl;
          };
          pressanykey();
          break;
        case 'i' :
          cout << "Grafo cargado desde " << nombrefichero << endl;
          G.Info_Grafo();
          pressanykey();
          break;
        case 's':
          if (G.Es_dirigido()) {
            cout << "Lista de sucesores: \n";
            G.Mostrar_Listas(1);
          }
          pressanykey();
          break;
        case 'e':
          if (G.Es_dirigido()) {
            cout << "Lista de predecesores: \n";
            G.Mostrar_Listas(-1);
          }
          pressanykey();
          break;
        case 'a':
          if (!G.Es_dirigido()) {
            cout << "Lista de adyacencia: \n";
            G.Mostrar_Listas(1);
          }
          pressanykey();
          break;
        case 'm':
          G.RecorridoAmplitud();
          pressanykey();
          break;
        case 'r':
          G.RecorridoProfundidad();
          pressanykey();
          break;
        case 'k':
          if (!G.Es_dirigido()) {
            G.Kruskal();
            pressanykey();
          }
          break;
      }
      if (opcion == 'q')
        break;
    } while (true);
  }
  cout << "Fin del programa" << endl;
  return 0;
};