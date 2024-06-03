#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void suma (ifstream& in1, ifstream& in2, const string& nombre) {
    ofstream out1(nombre);
    if (!in1.is_open() && !in2.is_open())
        cerr << "puta"; 
    string a;
    string b;
    while(in1 && in2) {
        in1 >> a;
        in2 >> b;
        out1 << a << " " << b << " ";
        a.clear();
        b.clear();
    }
    
    if (in1) {
        in1 >> a;
        out1 << a << " ";
        a.clear();
    }
    if (in2) {
        in2 >> a;
        out1 << a << " ";
        a.clear();
    }
    
    in1.close();
    in2.close();
    out1.close();
}

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(const int argc, char* argv[]) {
    string nombre1;
    //cin >> nombre1;
    ifstream fichero1(argv[1]);
    ifstream fichero2(argv[2]);
    suma(fichero1, fichero2, nombre1);
    return 0;
}