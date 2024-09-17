# #include <iostream>
# 
# using namespace std;
# 
# int main(void){
#   double num1, num2, EPS = 0.0001;
#   
#   while(true) {
#     cout << "Introduzca dos numeros decimales positivos a comparar: ";
#     cin >> num1 >> num2;
#     if (num1 <= EPS || num2 <= EPS)
#       break;
# 
#     if (num1 - num2 < 0) {
#       double temp{num2};
#       num2 = num1;
#       num1 = temp;
#     }
#     cout << "\nEl numero mayor entre " << num1 << " y " << num2 << " es " << num1 << endl;
#     cout << "El numero entero es: " << int(num1) << endl;
#   }
#   return 0;
# }

  .data
strIntro: .asciiz "Introduzca dos numeros decimales positivos a comparar: "
strCompara: .asciiz "\nEl numero mayor entre "
strY: .asciiz " y "
strEs: .asciiz " es "
strEndl: .asciiz "\n"
strInt: .asciiz "El numero entero es: "

# num1 -> $f20
# num2 -> $f22
# EPS  -> $f24
# cero -> $f26
# temp -> $f6

  .text

# int main(void){
main:

#   double num1, num2, EPS = 0.0001;
  li.d $f24, 0.0001
  li.d $f26, 0.0

#   while(true) {
while:
#     cout << "Introduzca dos numeros decimales positivos a comparar: ";
  li $v0, 4
  la $a0, strIntro
  syscall

#     cin >> num1 >> num2;
  li $v0, 7
  syscall
  mov.d $f20, $f0

  syscall
  mov.d $f22, $f0

#     if (num1 <= EPS || num2 <= EPS)
#       break;
  c.le.d $f20, $f24
  bc1t while_fin

  c.le.d $f22, $f24
  bc1t while_fin
 

#     cout << "\nEl numero mayor entre " << num1 << " y " << num2 << " es " << num1 << endl;
  li $v0, 4
  la $a0, strCompara
  syscall

  li $v0, 3
  mov.d $f12, $f20
  syscall

  li $v0, 4
  la $a0, strY
  syscall

  li $v0, 3
  mov.d $f12, $f22
  syscall

  li $v0, 4
  la $a0, strEs
  syscall

#     if (num1 - num2 < 0) {
  sub.d $f4, $f20, $f22
  c.lt.d $f4, $f26
  bc1f if_fin
#       double temp{num2};
  mov.d $f6, $f22
#       num2 = num1;
  mov.d $f22, $f20
#       num1 = temp;
  mov.d $f20, $f6

#     }
if_fin:

  li $v0, 3
  mov.d $f12, $f20
  syscall

  li $v0, 4
  la $a0, strEndl
  syscall

#     cout << "El numero entero es: " << int(num1) << endl;
  cvt.w.d $f4, $f20
  mfc1 $t0, $f4
  li $v0, 1
  move $a0, $t0
  syscall

  li $v0, 4
  la $a0, strEndl
  syscall

  b while
#   }
while_fin:
#   return 0;
  li $v0, 10
  syscall
# }