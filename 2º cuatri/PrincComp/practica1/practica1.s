#int main() {
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


# Uso de los rgistros:
# $s0 <- x
# $s1 <- es_primo
# $s2 <- i

    .data
strIntro    .asciiz "Introduce un numero primo: "
strSalida   .asciiz "Correcto. El numero introducido es primo.\n"
    .text
main:

    li  $v0, 10
    syscall
