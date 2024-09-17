# #include <iostream>
# 
# int main() {
#   long numero;
# 
#   while (true) {
#     int secuencias{0};
#     double media{0};
#     std::cout << "introduce el numero de collatz, escribe 0 para salir: \n";
#     std::cin >> numero;
#     if (numero == 0) {
#       break;
#     }
# 
#     while (numero > 1) {
#       if (numero % 2 == 0) {
#         numero /= 2;
#       } else {
#         numero = numero * 3 + 1;
#       }
# 
#       std::cout << numero << " ";
#       secuencias++;
#       media += numero;
#     }
#     std::cout << std::endl;
#     std::cout << "valor medio de la secuencia: " << media / secuencias << std::endl;
#   }
#   return 0;
#}

  .data
msg: .asciiz "introduce el numero de collatz, escribe 0 para salir: "
space: .asciiz " "
newline: .asciiz "\n"
valor_medio: .asciiz "valor medio de la secuencia: "

# numero -> $s0
# secuencia -> $f20
# media -> $f22

.text

# #include <iostream>
# 
# int main() {
#   long numero;
main:
# 
#   while (true) {
while:

#     double secuencias{0};
  li.d $f20, 0.0
#     double media{0};
  li.d $f22, 0.0
#     std::cout << "introduce el numero de collatz, escribe 0 para salir: \n";
  li $v0, 4
  la $a0, msg
  syscall

#     std::cin >> numero;
  li $v0, 5
  syscall
  move $s0, $v0

#     if (numero == 0) {
#       break;
  beqz $s0, while_fin
#     }
# 
#     while (numero > 1) {
while2:
  ble $s0, 1, while2_fin
#       if (numero % 2 == 0) {
  rem $t0, $s0, 2
  bnez $t0, else

#         numero /= 2;
  div $s0, $s0, 2
  b if_fin
#       } else {
else:
#         numero = numero * 3 + 1;
  mul $s0, $s0, 3
  addi $s0, 1

#       }
# 
if_fin:

#       std::cout << numero << " ";
  li $v0, 1
  move $a0, $s0
  syscall
  li $v0, 4
  la $a0, space
  syscall

#       secuencias++;
  li.d $f10, 1.0
  add.d $f20, $f20, $f10

#       media += numero;
  mtc1 $s0, $f4
  cvt.d.w $f6, $f4
  add.d $f22, $f22, $f6

  b while2
#     }
while2_fin:
#     std::cout << std::endl;
  li $v0, 4
  la $a0, newline
  syscall

#     std::cout << "valor medio de la secuencia: " << media / secuencias << std::endl;
  li $v0, 4
  la $a0, valor_medio
  syscall

  li $v0, 3
  div.d $f12, $f22, $f20
  syscall

  li $v0, 4
  la $a0, newline
  syscall

  b while
#   }
while_fin:

#   return 0;
li $v0, 10
syscall