#include <iostream>

using namespace std;

int main(void){
  double num1, num2, EPS = 0.0001;
  
  while(true) {
    cout << "Introduzca dos numeros decimales positivos a comparar: ";
    cin >> num1 >> num2;
    if (num1 <= EPS || num2 <= EPS)
      break;

    cout << "\nEl numero mayor entre " << num1 << " y " << num2 << " es ";
    if (num1 - num2 < 0) {
      double temp{num2};
      num2 = num1;
      num1 = temp;
    }
    cout << num1 << endl << "El numero entero es: " << int(num1) << endl;
  }
  return 0;
}