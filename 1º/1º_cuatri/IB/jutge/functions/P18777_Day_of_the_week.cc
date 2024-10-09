#include <iostream>

std::string day_of_the_week (int dia, int mes, int año) {
  mes -= 2;
  if (mes <= 0) {
    mes +=12;
    año -=1;
  }
  int century{0};
  int a{0};
  century = año / 100;
  a = año % 100;
  int fecha{0};
  fecha = (2.6 * mes) + dia + a + (a / 4) + (century / 4) - 2 * century;
  if (fecha < 0) {
    fecha += 7;
  }
  std::string dia_semana;
  fecha %= 7;
  switch (fecha) {
  case 0:
    dia_semana = "Sunday";
    return dia_semana;
    break;
  case 1:
    dia_semana = "Monday";
    return dia_semana;
    break;
  case 2:
    dia_semana = "Tuesday";
    return dia_semana;
    break;
  case 3:
    dia_semana = "Wednesday";
    return dia_semana;
    break;
  case 4:
    dia_semana = "Thursday";
    return dia_semana;
    break;
  case 5:
    dia_semana = "Friday";
    return dia_semana;
    break;
  case 6:
    dia_semana = "Saturday";
    return dia_semana;
    break;
  }
  return 0;
}

bool Bisiesto(int año) {
  if (año % 100 == 0) {
    if ((año / 100) % 4 == 0)
      return true;
    return false;
  } else {
    if (año % 4 == 0)
      return true;
    return false;
  }
}


bool CheckCorrectDate (int dia, int mes, int año) {
  if (dia < 1 || mes < 1 || año < 1800 || dia > 31 || mes > 12 || año > 9999) {
    return false;
  }
    if (!Bisiesto(año) && mes == 2 && dia > 28) {
    return false;
  }
  if (mes == 2 && dia > 29) {
    return false;
  }
  if ((mes > 7 && mes % 2 != 0 && dia > 30) ||
      (mes <= 7 && mes % 2 == 0 && dia > 30)) {
    return false;
  }
  return true;
}

int main() {
  int dia, mes, año;
  while (std::cin >> dia >> mes >> año) {
    if (CheckCorrectDate(dia, mes, año) == 1){
    std::cout << "day_of_the_week(" << dia << ", " << mes << ", " << año << ") → " << day_of_the_week(dia, mes, año) << std::endl;
    } else {continue;}
  }
  return 0;
}