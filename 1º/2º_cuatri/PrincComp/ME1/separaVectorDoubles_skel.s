# ME1: Separa Vector doubles
# Realizar un programa que trabaja con vectores número en punto flotante de
# doble precisión (double) mostrando que elementos son mayores que la media
# y cuales menores.

# alumno: Darío Regalado González alu0101640150
# fecha: 2 mayo 2024

	.data
nOptions = 3
sizeD = 8

str_mayor_igual_que: .asciiz " es mayor o igual"
str_que_la_media:    .asciiz " que la media\n"
str_menor_que:       .asciiz " es menor"

str_titulo:         .asciiz "\nSepara Elementos Según Media de Vector de Doubles\n"
str_elige:           .asciiz "\nElige vector de trabajo (1, 2, 3) o 0 para terminar: "
str_incorrecta:      .asciiz "Opción incorrecta"
str_termina:         .asciiz "\nTermina el programa\n"
v1:      .double -3.18, 8.8, 7.73, -0.71, -5.26, -3.89, -3.32, -0.39, 0.15, 0.98
v1Largo: .word 10
v2:      .double -1.06, 5.65, 2.96, -1.64, -2.92, -0.36
v2Largo: .word 6
v3:      .double 0.0
v3Largo: .word 0

	.text
# ↓↓↓↓ Debes codificar a partir de aquí ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

# double media(double* vect, int n) {
media:

# $t0 -> vect
# $t1 -> n
# $t2 -> i
# $t3 ->
# $f4 -> acumulado
# $f6 -> vect[i]
# $f8 -> n en doble prescision
# $f0 -> mediaAritmetica

	move $t0, $a0
	move $t1, $a1

#   double acumulado = 0.0;
	li.d $f4, 0.0
#   for(int i = 0; i < n; i++) {
	li $t2, 0
for_media:
	bge $t2, $t1, for_media_fin
	
#     acumulado = acumulado + vect[i];
	l.d $f6, 0($t0)
	add.d $f4, $f4, $f6
	addi $t0, sizeD 
#   }
	addi $t2, 1
	b for_media
for_media_fin:

#   double mediaAritmetica = acumulado / n;
#   return mediaAritmetica;
	mtc1 $t1, $f8
	cvt.d.w $f8, $f8
	div.d $f0, $f4, $f8 # se guarda directamente el valor de retorno en $f0
	jr $ra
media_fin:
# }





# void separa(double* v, int largo) {
separa:
	
	addi $sp, -32
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	s.d $f20, 12($sp)
	s.d $f22, 20($sp)
	sw $ra, 28($sp)

	move $s0, $a0
	move $s1, $a1

# $s0 -> v
# $s1 -> largo
# $s2 -> i
# $f20 -> valor
# $f22 -> mediaVector

#   double mediaVector = media(v, largo);
	move $a0, $s0
	move $a1, $s1
	jal media # los parmetros v y largo ya se encuentran en los registros correspondientes
	mov.d $f22, $f0

#   for(int i = 0; i < largo; i++) {
	li $s2, 0
for_separa:
	bge $s2, $s1, for_separa_fin
	
#     double valor = v[i];
	l.d $f20, 0($s0)
	
#     std::cout << valor;
	li $v0, 3
	mov.d $f12, $f20
	syscall
	
#     if (valor >= mediaVector) {
if_separa:
	c.lt.d $f20, $f22
	bc1t else_separa
	
#       std::cout << " es mayor o igual";
	li $v0, 4
	la $a0, str_mayor_igual_que
	syscall
	b if_separa_fin

#     } else {
else_separa:
#       std::cout << " es menor";
	li $v0, 4
	la $a0, str_menor_que
	syscall
	
#     }
if_separa_fin:
#     std::cout << " que la media\n";
	#li $v0, 4
	la $a0, str_que_la_media
	syscall
#   }
	addi $s0, sizeD # actualizo el indice de la posicion del vector para mayor optimizacion
	addi $s2, 1
	b for_separa
for_separa_fin:
# }
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	l.d $f20, 12($sp)
	l.d $f22, 20($sp)
	lw $ra, 28($sp)
	addi $sp, 32
	jr $ra
separa_fin:




#  ↑↑↑↑↑ Debes codificar hasta aquí ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
# int main() {
main:
    # Imprimir mensaje de bienvenida
    la $a0, str_titulo
    li $v0, 4
    syscall

    # Bucle principal
main_loop:
    # Solicitar al usuario que elija un vector
    la $a0, str_elige
    li $v0, 4
    syscall

    # Leer la opción del usuario
    li $v0, 5
    syscall
    move $t0, $v0       # Guardar la elección en $t0

    # Chequear si se debe terminar
    beqz $t0, exit      # Si $t0 es 0, terminar

    # Verificar la validez de la elección
    bltz $t0, error_option
    ble $t0, nOptions, non_error_option

error_option:
    # Manejar elección inválida
    la $a0, str_incorrecta
    li $v0, 4
    syscall
    j main_loop

non_error_option:
    # Asignar el vector correspondiente y su tamaño
    lw $s2, v1Largo          # v1Largo
    la $s3, v1          # Dirección de v1
    bne $t0, 1, check_v2
    j process

check_v2:
    lw $s2, v2Largo           # v2Largo
    la $s3, v2          # Dirección de v2
    bne $t0, 2, check_v3
    j process

check_v3:
    lw $s2, v3Largo           # v3Largo
    la $s3, v3          # Dirección de v3

process:
# ↓↓↓↓ Debes codificar a partir de aquí ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
# vTrabajo → s3
# largoTrabajo → s2

#     separa(vTrabajo, largoTrabajo);
	move $a0, $s3
	move $a1, $s2
	jal separa

#  ↑↑↑↑↑ Debes codificar hasta aquí ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
#   }
    j main_loop
exit:
    # std::cout << "\nTermina el programa\n";
    li $v0,4
    la $a0,str_termina
    syscall
    # Salir del programa
    li $v0, 10
    syscall
#}
