 /*
 *  Programa principal.
 *
 *
 *               Autores : Antonio Sedeno Noda, Sergio Alonso.
 *               Cursos  : 2012-2021
 */

#include <string.h>
#include "grafo.h"

char getch();
void pressanykey();
void clrscr();


void menu (unsigned dirigido, char &opcion)
//Expresion del menu de opciones segun sea un grafo dirigido o no dirigido
{
    cout << "Optimiza!cion en Grafos, 2023-2024 Darío Regalado González" << endl;
    cout << "c. [c]argar grafo desde fichero" << endl;
    if (dirigido == 0) //Grafo no dirigido
            {
            cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
            cout << "a. Mostrar la lista de [a]dyacencia del grafo" << endl;
            cout << "y. Mostrar la matriz de ad[y]acencia del grafo" << endl;
            cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo" << endl;
            cout << "r. Realizar un recorrido en p[rJofundidad del grafo desde un nodo" << endl;
            cout << "o. Mostrar c[o]mponentes conexas del grafo" << endl;
            cout << "k. Mostrar árbol generador minimo coste, [k]ruskal" << endl;
            cout << "p. Mostrar árbol generador minimo coste, [p]rim" << endl;
	    //Aqu� se a�aden m�s opciones al men� del grafo no dirigido
            }
    else
            {
            cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
            cout << "s. Mostrar la lista de [s]ucesores del grafo" << endl;
            cout << "e. Mostrar la lista de [p]redecesores del grafo" << endl;
            cout << "y. Mostrar la matriz de ad[y]acencia del grafo" << endl;
            cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo porsucesores" << endl;
            cout << "r. Realizar un recorrido en p[r]ofundidad del grafo desde un nodo plor sucesores" << endl;
            cout << "d. Caminos mínimos: [d]ijkstra" << endl;
            cout << "v. Caminos mínimos: Comparamos Dijkstra [v]s BellmanFordEnd" << endl;
            cout << "f. Caminos mínimos: [f]loyd-warshall" << endl;

	    //Aqu� se a�aden m�s opciones al men� del grafo dirigido" << endl;
            };
    cout << "q. Finalizar el programa" << endl;
    cout << "Introduce la letra de la accion a ejecutar  > ";
    cin >> opcion;
};


// El principal es simplemente un gestor de menu, diferenciando acciones para dirigido y para no dirigido, y un men� inicial si no hay un grafo cargado
int main(int argc, char *argv[])
{
    int error_apertura;
    char nombrefichero[85], opcion;
    clrscr();
    //Si tenemos el nombre del primer fichero por argumento, es una excepcion, y lo intentamos cargar, si no, lo pedimos desde teclado
    if (argc > 1)
    {
	cout << "Cargando datos desde el fichero dado como argumento" << endl;
        strcpy(nombrefichero, argv[1]);
    }
    else
    {
        cout << "Introduce el nombre completo del fichero de datos" << endl;
        cin >> nombrefichero;
    };
    GRAFO G(nombrefichero, error_apertura);
    if (error_apertura == 1)
    {
        cout << "Error en la apertura del fichero desde argumento: revisa nombre y formato" << endl;
        pressanykey();
        clrscr();
    }
    else
    {
        cout<< "Grafo cargado desde el fichero " << nombrefichero << endl;
        pressanykey();
        clrscr();
        do
        {
            menu(G.Es_dirigido(), opcion);
            switch (opcion)
            {
                case 'c' :
                    clrscr();
         	    cout << "Introduce el nombre completo del fichero de datos" << endl;
                    cin >> nombrefichero;
                    G.actualizar(nombrefichero, error_apertura);
                    if (error_apertura == 1)
                    {
                        cout << "Error en la apertura del fichero: revisa nombre y formato : puedes volver a intentarlo" << endl;
                    }
                    else
                    {
                        cout << "Fichero cargado correctamente desde " << nombrefichero << endl;
                    };
                    pressanykey();
                    clrscr();
                    break;

                case 'i' :
                    clrscr();
		    cout << "Grafo cargado desde " << nombrefichero << endl;
                    G.Info_Grafo();
                    pressanykey();
                    clrscr();
                    break;

                case 's' :
                    clrscr();
		    cout << "lista de sucesores del grafo " << nombrefichero << endl;
                    G.Mostrar_Listas(1);
                    pressanykey();
                    clrscr();
                    break;

                case 'e' :
                    clrscr();
		    cout << "lista de predecesores del grafo " << nombrefichero << endl;
                    G.Mostrar_Listas(-1);
                    pressanykey();
                    clrscr();
                    break;

                case 'y' :
                    clrscr();
		    cout << "Matriz de adyacencia del grafo " << nombrefichero << endl;
                    G.Mostrar_Listas(0);
                    pressanykey();
                    clrscr();
                    break;

                case 'm' :
                    clrscr();
		    cout << "Grafo cargado desde " << nombrefichero << endl;
                    G.RecorridoAmplitud();
                    pressanykey();
                    clrscr();
                    break;

                case 'r' :
                    clrscr();
		    cout << "Recorrido en p[rJofundidad del grafo " << nombrefichero << endl;
                    G.RecorridoProfundidad();
                    pressanykey();
                    clrscr();
                    break;

                case 'o' :
                    clrscr();
		    cout << "Grafo cargado desde " << nombrefichero << endl;
                    G.Info_Grafo();
                    pressanykey();
                    clrscr();
                    break;

                case 'k' :
                    clrscr();
		    cout << "Grafo cargado desde " << nombrefichero << endl;
                    G.Info_Grafo();
                    pressanykey();
                    clrscr();
                    break;
                case 'p' :
                    clrscr();
		    cout << "Grafo cargado desde " << nombrefichero << endl;
                    G.Info_Grafo();
                    pressanykey();
                    clrscr();
                    break;
		 //Situar aqu� el resto de opciones del men�
            }
    }
    while (opcion != 'q');
    }
    cout << "Fin del programa" << endl;
	return(0);
};




#ifdef _WIN32
    #include <conio.h>
#else
    #include <unistd.h>
    #include <termios.h>
    char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
            perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
            perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
            perror("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
            perror ("tcsetattr ~ICANON");
        return (buf);
    }
#endif

void pressanykey() {
    std::cout << "Presiona cualquier tecla para continuar...";
    getch();
    std::cout << "\n";
}

#ifdef _WIN32
    #include <windows.h>
    void clrscr() {
        COORD topLeft  = { 0, 0 };
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO screen;
        DWORD written;

        GetConsoleScreenBufferInfo(console, &screen);
        FillConsoleOutputCharacterA(
            console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
        );
        FillConsoleOutputAttribute(
            console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
            screen.dwSize.X * screen.dwSize.Y, topLeft, &written
        );
        SetConsoleCursorPosition(console, topLeft);
    }
#else
    #include <stdio.h>
    void clrscr() {
        printf("\033[H\033[J");
    }
#endif

