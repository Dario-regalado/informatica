#include <iostream>
#include <algorithm>

int MaxCommonDivisor(long long numero1, long long numero2){
  long long mcd{0};
  long long mayor{std::max(numero1, numero2)};
  long long menor{std::min(numero1, numero2)};
  do
  {
    mcd = menor;
    menor = mayor % menor;
    mayor = mcd;
  } while (menor != 0);
  return mcd;
  
}
long long MinCommonMultiple(long long numero1, long long numero2){
  long long produtco{(numero1 * numero2) / MaxCommonDivisor(numero1, numero2)};
  return produtco;
}

int main() {
  long long numero1{0};
  long long numero2{0};
  while (std::cin >> numero2) {
    long long int producto{1};
    if (numero2 == 0) {
      break;
    } else{
      for (int i = 0; i < numero2; i++) {
        std::cin >> numero1;
        producto = MinCommonMultiple(producto, numero1);
      }
      std::cout << producto << std::endl;
      
    }
    
  }
  
}
/*

#include<iostream>
using namespace std;
 
long int mcd(long int n1, long int n2) {
    if(n1 < n2) return mcd(n2,n1);
    if(n2 == 0) return n1;
    return mcd(n2, n1 % n2);
}
 
long int mcm(long int n1, long int n2) {
    long int producto = (n1*n2)/mcd(n1,n2);
    return producto;
}

int main() {
    long int numero1;
    long int numero2;
    while (cin >> numero2) {
        long int producto = 1;
        if (numero2 == 0);
        else {
            int i = 0;
            while (i < numero2) {
                cin >> numero1;
                producto = mcm(producto, numero1);
                i++;
            }
            cout << producto << endl;
        }
    }
}*/