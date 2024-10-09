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
    l.d $f12, 0($s0)
    li $v0, 3
    syscall
    li $v0, 11
    li $a0, ' '
    syscall

    addi $s0, $s0, sizeD

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
    add $t4, $t4, $t0
    l.d $f4, 0($t4)

    mul $t4, $t3, sizeD
    add $t4, $t4, $t0
    l.d $f6, 0($t4)

    c.lt.d $f4, $f6
    bc1t if_ordenado_fin

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
merge:
    addi $sp, -36
    sw $s0, 0($sp)
    sw $s1, 4($sp)
    sw $s2, 8($sp)
    sw $s3, 12($sp)
    sw $s4, 16($sp)
    sw $s5, 20($sp)
    sw $s6, 24($sp)
    sw $s7, 28($sp)
    sw $ra, 32($sp)

# s0-> o1
# s1-> o2
# s2-> v1
# s3-> n1
# s4-> v2
# s5-> n2
# s6 -> i
# s7 -> j
    move $s2, $a0
    move $s3, $a1
    move $s4, $a2
    move $s5, $a3

#     int  o1 = ordenado(v1,n1);
#     if (o1 == 0) return;
    jal ordenado
    move $s0, $v0
    beq $s0, 0, merge_fin

#     int o2 = ordenado(v2,n2);
#     if (o2 == 0) return;
    move $a0, $s4
    move $a1, $s5
    jal ordenado
    move $s1, $v0
    beq $s1, 0, merge_fin

    li $s6, 0 #     int i = 0; // índice para recorrer el v1
    li $s7, 0 #     int j = 0; // índice para recorrer el v2
#     while ( ( i < n1) && (j < n2) ) {
while1_merge:
    bge $s6, $s3, while1_merge_fin
    bge $s7, $s5, while1_merge_fin

    mul $t0, $s6, sizeD
    add $t0, $t0, $s2
    l.d $f4, 0($t0)
    mul $t1, $s7, sizeD
    add $t1, $t1, $s4
    l.d $f6, 0($t1)
#         if (v1[i] >= v2[j]) {
    c.lt.d $f4, $f6
    bc1f else

#             std::cout << v1[i] << " ";
    li $v0, 3
    mov.d $f12, $f4
    syscall
    li $v0, 11
    li $a0, ' '
    syscall
#             i++;
    addi $s6, 1
    b while1_merge
#         }
#         else {
else:
#             std::cout << v2[j] << " ";
    li $v0, 3
    mov.d $f12, $f6
    syscall
    li $v0, 11
    li $a0, ' '
    syscall
#             j++;
    addi $s7, 1
#         }
#     }
    b while1_merge
while1_merge_fin:
#     while ( i < n1) {
while2_merge:
    bge $s6, $s3, while2_merge_fin
    mul $t0, $s6, sizeD
    add $t0, $s2, $t0
#         std::cout << v1[i] << " ";
    li $v0, 3
    l.d $f12, 0($t0)
    syscall
    li $v0, 11
    li $a0, ' '
    syscall
#         i++;
    addi $s6, 1
#     }
    b while2_merge
while2_merge_fin:

#     while ( j < n2) {
while3_merge:
    bge $s7, $s5, while3_merge_fin

#         std::cout << v2[j] << " ";
    mul $t1, $s7, sizeD
    add $t1, $t1, $s4
    li $v0, 3
    l.d $f12, 0($t1)
    syscall
    li $v0, 11
    li $a0, ' '
    syscall
#         j++;
    addi $s7, 1 
#     }
    b while3_merge
while3_merge_fin:
#     std::cout << "\n";
    li $v0, 11
    li $a0, '\n'
    syscall

merge_fin:
    lw $s0, 0($sp)
    lw $s1, 4($sp)
    lw $s2, 8($sp)
    lw $s3, 12($sp)
    lw $s4, 16($sp)
    lw $s5, 20($sp)
    lw $s6, 24($sp)
    lw $s7, 28($sp)
    lw $ra, 32($sp)
    addi $sp, 36
    jr $ra
#     return;
# }



# int main(void) {
main:

#     std::cout << "\nVector con dimension " << n1 << std::endl;
    li $v0, 4
    la $a0, cad1
    syscall
    li $v0, 1
    lw $a0, n1
    syscall 
    li $v0, 11
    li $a0, '\n'
    syscall

#     printvec(v1,n1);
    la $a0, v1
    lw $a1, n1
    jal printvec
  
#     std::cout << "\nVector con dimension " << n2 << std::endl;
    li $v0, 4
    la $a0, cad1
    syscall
    li $v0, 1
    lw $a0, n2
    syscall
    li $v0, 11
    li $a0, '\n'
    syscall


#     printvec(v2,n2);
    la $a0, v2
    lw $a1, n2
    jal printvec
  
#     std::cout << "\nVector con dimension " << n3 << std::endl;
    li $v0, 4
    la $a0, cad1
    syscall
    li $v0, 1
    lw $a0, n3
    syscall
    li $v0, 11
    li $a0, '\n'
    syscall

#     printvec(v3,n3);
    la $a0, v3
    lw $a1, n3
    jal printvec
  
#     std::cout << "\nIntentando mezcla con dos vectores ...\n";
    li $v0, 4
    la $a0, cad2
    syscall

#     merge(v1,n1,v2,n2);
    la $a0, v1
    lw $a1, n1
    la $a2, v2
    lw $a3, n2
    jal merge

#     std::cout << "\nIntentando mezcla con dos vectores ...\n";
    li $v0, 4
    la $a0, cad2
    syscall
#     merge(v1,n1,v3,n3);
    la $a0, v1
    lw $a1, n1
    la $a2, v3
    lw $a3, n3
    jal merge

#     std::cout << "\nFIN DEL PROGRAMA\n";
    li $v0, 4
    la $a0, cad3
    syscall
    li $v0, 10
    syscall
#     return(0);
# }

