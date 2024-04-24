# Principio de Computadores. Preparación para el Microexamen
# Operaciones con funciones y direccionamiento indirecto
# Autor: 
# Fecha última modificación: 
#include <iostream>

# const int n1 = 10;
# double v1[n1] = {10.5, 9.5, 7.25, 6.25, 5.75, 4.5, 4.25, 3.5, -1.5, -2.0};
# const int n2 = 5;
# double v2[n2] = {5.5, 4.5, 4.25, 2.5, 2.5 };
# const int n3 = 4;
# double v3[n3] = {7.0, 5.0, 2.0, 1.0};

sizeD = 8
LF = 10
SPACE = 32

    .data
n1:     .word 10
v1:     .double 10.5, 9.5, 7.25, 6.25, 5.75, 4.5, 4.25, 3.5, -1.5, -2.0
n2:     .word 5
v2:     .double 5.5, 4.5, 4.25, 2.5, 2.5
n3:     .word 4
v3:     .double 7.0, 5.0, 2.0, 1.0
cad1:   .asciiz "\nVector con dimension "
cad2:   .asciiz "\nIntentando mezcla con dos vectores ...\n"
cad3:   .asciiz "\nFIN DEL PROGRAMA\n"

    .text

# void printvec(double *v, const int n) {


printvec:
    addi $sp, -16
    sw $s0, 0($sp)
    sw $s1, 4($sp)
    sw $s2, 8($sp)
    sw $ra, 12($sp)

# s0 -> v*
# s1 -> n
# s2 -> i
    move $s0, $a0
    move $s1, $a1


#     for (int i = 0; i < n; i++)
    li $s2, 0
for_printvec:
    bge $s2, $s1, for_printvec_fin
#         std::cout << v[i] << " ";
    swc1 $f12, 0($s0)
    li $v0, 7
    syscall
    addi $s0, sizeD

    addi $s2, 1
    b for_printvec
for_printvec_fin:
#     std::cout << "\n";
    li $v0, 11
    li $a0, '\n'
    syscall
    
#     return;
    lw $s0, 0($sp)
    lw $s1, 4($sp)
    lw $s2, 8($sp)
    lw $ra, 12($sp)
    addi $sp, 16
    jr $ra
# }
printvec_fin:




# int ordenado(double *v, const int n) {
ordenado:

#t0 -> v*
#t1 -> n
#t2 -> resultado
#t3 -> i
#t4 -> index

    move $t0, $a0
    move $t1, $a1

#     int resultado = 1;
#     int i = 0;
    li $t2, 1
    li $t3, 0
    addi $t1, -1
#     while (i < n-1) {
while_ordenado: 
    bge $t3, $t1, while_ordenado_fin
if_ordenado:
#         if (v[i+1] >= v[i]) {
    addi $t4, $t3, 1
    mul $t4, $t4, sizeD
    addi $t4, $t4, $t0
    l.d $f4, 0($t4)

    li $t4, $t3
    mul $t4, $t4, sizeD
    addi $t4, $t4, $t0
    l.d $f6, 0($t4)

    c.lt.d $f4, $f6
    bc1f if_ordenado_fin

#             resultado = 0;
    li $t2, 0
#             break;
    b while_ordenado_fin
#         }
if_ordenado_fin:

#         i++;
    addi $t3, 1
    b while_ordenado
#     }
while_ordenado_fin:
#     return(resultado);
    move $v0, $t2
    jr $ra
# }




# void merge(double *v1, const int n1,double *v2, const int n2) {
#     int  o1 = ordenado(v1,n1);
#     if (o1 == 0) return;
#     int o2 = ordenado(v2,n2);
#     if (o2 == 0) return;
#     int i = 0; // índice para recorrer el v1
#     int j = 0; // índice para recorrer el v2
#     while ( ( i < n1) && (j < n2) ) {
#         if (v1[i] >= v2[j]) {
#             std::cout << v1[i] << " ";
#             i++;
#         }
#         else {
#             std::cout << v2[j] << " ";
#             j++;
#         }
#     }
#     while ( i < n1) {
#         std::cout << v1[i] << " ";
#         i++;
#     }
#     while ( j < n2) {
#         std::cout << v2[j] << " ";
#         j++;
#     }
#     std::cout << "\n";
#     return;
# }

# int main(void) {
#     std::cout << "\nVector con dimension " << n1 << std::endl;
#     printvec(v1,n1);
  
#     std::cout << "\nVector con dimension " << n2 << std::endl;
#     printvec(v2,n2);
  
#     std::cout << "\nVector con dimension " << n3 << std::endl;
#     printvec(v3,n3);
  
#     std::cout << "\nIntentando mezcla con dos vectores ...\n";
#     merge(v1,n1,v2,n2);
#     std::cout << "\nIntentando mezcla con dos vectores ...\n";
#     merge(v1,n1,v3,n3);

#     std::cout << "\nFIN DEL PROGRAMA\n";
#     return(0);
# }

