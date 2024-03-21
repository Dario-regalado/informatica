 /*
 *  GRAFO.CPP - Plantilla para la implementaci�n de la clase GRAFOS
 *
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos   : 2012-2021
 */

#include "grafo.h"

void GRAFO :: destroy()
{
	for (unsigned i=0; i< n; i++)
    {
		LS[i].clear();
		if (dirigido == 1)
        {
            LP[i].clear();
        };
	}
	LS.clear();
	LP.clear();

}

void GRAFO :: build (char nombrefichero[85], int &errorapertura)
{
    ElementoLista     dummy;
	ifstream textfile;
	textfile.open(nombrefichero);
	if (textfile.is_open())
    {
		unsigned i, j, k;
		// leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
		textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
		// los nodos internamente se numeran desde 0 a n-1
		// creamos las n listas de sucesores
		LS.resize(n);

        // si el grafo es dirigido, creamos la lista de n predecesores
        if (dirigido == 1)
            LP.resize(n);

        // leemos los m arcos
		for (k=0;k<m;k++)
        {
			textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
			//damos los valores a dummy.j y dummy.c
			
            //situamos en la posici�n del nodo i a dummy mediante push_back
            dummy.j = j - 1;
            LS[i - 1].push_back(dummy);
			
            //pendiente de hacer un segundo push_back si es no dirigido. O no.
            if (dirigido == 1) {
                dummy.j = i - 1;
                LP[j - 1].push_back(dummy);
                continue;                                                                                /*revisar*/
            } else if (i != j) {
                dummy.j = i - 1;
                LS[j - 1].push_back(dummy);
            }

			//pendiente la construcci�n de LP, si es dirigido
			//pendiente del valor a devolver en errorapertura
			//...
        }
        textfile.close();
        errorapertura = 0;
    }

}

GRAFO::~GRAFO()
{
	destroy();
}

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura)
{
	build (nombrefichero, errorapertura);
}

void GRAFO:: actualizar (char nombrefichero[85], int &errorapertura)
{
    //Limpiamos la memoria dinamica asumida en la carga previa, como el destructor
    destroy();
    //Leemos del fichero y actualizamos G con nuevas LS y, en su caso, LP
    build(nombrefichero, errorapertura);
}

unsigned GRAFO::Es_dirigido()
{
    return dirigido;
}

void GRAFO::Info_Grafo()
{
    cout << "numero de nodos: " << n << endl;
    cout << "numero de arcos: " << m << endl;
    cout << "el grafo es " << (dirigido ? "dirigido" : "no dirigido") << endl;
}

void Mostrar_Lista(vector<LA_nodo> L)
{
    for (int i{0}; i < L.size(); i++) {
        cout << i << ": ";
        for (int j{0}; j < L[i].size(); j++) {
            cout << "[" << L[i][j].j << ", " << L[i][j].c << "] ";
    }   
    cout << '\n';
  }
}

void GRAFO :: Mostrar_Listas (int l)
{
    if (l == 1)
        Mostrar_Lista(LS);
    else if (l == -1)
        Mostrar_Lista(LP);
}

void GRAFO::Mostrar_Matriz() //Muestra la matriz de adyacencia, tanto los nodos adyacentes como sus costes
{

}

void GRAFO::dfs_num(unsigned i, vector<LA_nodo>  L, vector<bool> &visitado, 
                    vector<unsigned> &prenum, unsigned &prenum_ind, 
                    vector<unsigned> &postnum, unsigned &postnum_ind) //Recorrido en profundidad recursivo con recorridos enum y postnum
{
	visitado[i] = true;
    prenum[prenum_ind++]=i;//asignamos el orden de visita prenum que corresponde el nodo i
    for (unsigned j=0;j<L[i].size();j++)
             if (!visitado[L[i][j].j])
                {
                dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
                };
    postnum[postnum_ind++]=i;//asignamos el orden de visita posnum que corresponde al nodo i
}

void GRAFO::RecorridoProfundidad()
{
    //definimos e inicializamos el vector de visita de los nodos
    vector<bool> visitado;
    visitado.resize(n, false);
    // definimos e inicializamos elos vectores de prenum y postnum
    vector<unsigned> prenum;
    prenum.resize(n, 0);
    vector<unsigned> postnum;
    postnum.resize(n, 0);
    // inicialiczamos los index
    unsigned prenum_ind = 0;
    unsigned postnum_ind = 0;
    //definimos las variable del nodo inicial
    unsigned i;
    //solicitamos por pantalla el nodo inicial i
    cout << "Vamos a construir un recorrido en profundidad\n";
    cout << "Elija nodo de partida? [1- " << n << "]: ";
    //almacenamos el valor en el nodo inicial i
    cin >> i;

    //realizamos el recorrido en profundidad
    dfs_num(i-1, LS, visitado, prenum, prenum_ind, postnum, postnum_ind);
    
    //imprimir los vectores
    cout << "Orden de visita de los nodos en preorden\n";
    for (unsigned k = 0; k < prenum.size(); k++) {
        if (k != prenum.size() -1){
            cout << "[" << prenum[k] << "] -> ";
        } else
        cout << "[" << prenum[k] << "]";
    }
    cout << "\nOrden de visita de los nodos en postorden\n";
    for (unsigned k = 0; k < postnum.size(); k++) {
        if (k != postnum.size() -1){
            cout << "[" << postnum[k] << "] -> ";
        } else
        cout << "[" << postnum[k] << "]";
    }
    cout << "\nPresione una tecla para continuar . . . \n";
    
}

void GRAFO::bfs_num(	unsigned i, //nodo desde el que realizamos el recorrido en amplitud
				vector<LA_nodo>  L, //lista que recorremos, LS o LP; por defecto LS
				vector<unsigned> &pred, //vector de predecesores en el recorrido
				vector<unsigned> &d) //vector de distancias a nodo i+1
//Recorrido en amplitud con la construcci�n de pred y d: usamos la cola
{
    vector<bool> visitado; //creamos e iniciamos el vector visitado
    visitado.resize(n, false);
    visitado[i] = true;

    pred.resize(n, 0); //creamos e inicializamos pred y d
    d.resize(n, 0);
    pred[i] = i;
    d[i] = 0;

    queue<unsigned> cola; //creamos e inicializamos la cola
    cola.push(i);//iniciamos el recorrido desde el nodo i+1

    while (!cola.empty()) //al menos entra una vez al visitar el nodo i+1 y contin�a hasta que la cola se vac�e
    {   unsigned k = cola.front(); //cogemos el nodo k+1 de la cola
        cola.pop(); //lo sacamos de la cola
        //Hacemos el recorrido sobre L desde el nodo k+1
        for (unsigned j=0; j<L[k].size();j++) //Recorremos todos los nodos u adyacentes al nodo k+1
        { 
            //Si el nodo u no est� visitado
            if (visitado[L[k][j].j] == false){
            //Lo visitamos
            visitado[L[k][j].j] = true;
            //Lo metemos en la cola
            cola.push(L[k][j].j);
            //le asignamos el predecesor
            pred[L[k][j].j] = k;
            //le calculamos su etiqueta distancia
            d[L[k][j].j] = d[k] + 1;
            }
        };
        //Hemos terminado pues la cola est� vac�a
    };
}

void GRAFO::RecorridoAmplitud() //Construye un recorrido en amplitud desde un nodo inicial
{
    //definimos los vectores pred y d
    vector<unsigned> pred;
    vector<unsigned> d;
    //definimos la variable del nodo inicial i
    unsigned i;
    //solicitamos por pantalla el nodo inicial
    cout << "Vamos a construir un recorrido en amplitud" << endl;
    cout << "Elije nodo de partida? [1 - " << n << "]: ";
    cin >> (unsigned&)i;
    cout << "Nodo inicial: " << i << endl;
    //realizamos el recorrido en amplitud
    bfs_num(i-1, LS, pred, d);

    //imprimir por pantalla la informacion
    cout << "\nNodos según distancia al nodo inicial en número de aristas";
    for (unsigned k = 0; k <= d.back(); k++)
    {
        cout << "\nDistancia " << k << " aristas:";
        for (unsigned c = 0; c < d.size(); c++) {
            if (d[c] == k) {
                cout << " " << c+1;
            }
        }
    }
    cout << "\nRamas de conexion en el recorrido";
    for (unsigned k = 0; k < pred.size(); k++)
    {
        cout << "\n" << k+1;
        unsigned j = k;
        while (j != pred[j]) {
            cout << " - " << pred[j]+1;
            j = pred[j];
        }
    }
}
