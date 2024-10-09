# int main() {
#  int x;
#  bool es_primo = true;
#
#  do {
#    std::cout << "Introduce un numero primo: ";
#    std::cin >> x;
#    for (int i = 2; i < x; ++i) {
#      es_primo =(x % i != 0);
#      if (!es_primo)
#        break;
#    } 
#  } while (es_primo == false);
#  std::cout << "Correcto. El numero introducido es primo.\n";
#  return 0;
#}


# Uso de los registros:
# $s0 <- x
# $s1 <- es_primo
# $s2 <- i

    .data
strIntro:    .asciiz "Introduce un numero primo: "
strSalida:   .asciiz "Correcto. El numero introducido es primo.\n"
    .text
main:
# int main() {
#  int x;
#  bool es_primo = true;
#
#  do {
do_while:
#    std::cout << "Introduce un numero primo: ";
    li $v0, 4
    la $a0, strIntro
    syscall

#    std::cin >> x;
    li $v0, 5
    syscall
    move $s0, $v0

#    for (int i = 2; i < x; ++i) {
    li $s2,2
for:
    bge $s2, $s0, for_end1

#      es_primo =(x % i != 0);
#      if (!es_primo)
#        break;
    rem $s1, $s0, $s2   # $t0 = x / i
    beqz    $s1, for_end1 # if $t0 == 0 (es_primo == false), then break

#    } 
    addi $s2,1
    b   for
for_end1:

#  } while (es_primo == false);
    beqz $s1, do_while
fin_do_while:

#  std::cout << "Correcto. El numero introducido es primo.\n";
    li $v0, 4
    la $a0, strSalida
    syscall

#  return 0;
#}
    li  $v0, 10
    syscall
