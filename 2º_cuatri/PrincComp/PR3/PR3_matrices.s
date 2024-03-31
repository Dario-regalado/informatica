#// Solución PR3 curso 23-24
#// Manejo de matrices con funciones
#
#
#typedef struct {
#  int nFil;
nFil = 0	# El desplazamiento al campo dentro de la estructura
#  int nCol;
nCol = 4	# El desplazamiento al campo dentro de la estructura
#  float elementos[];
elementos = 8	# El desplazamiento al campo dentro de la estructura
#} structMat;
#

sizeF = 4	# Numero de bytes de un float
LF = 10		# Caracter salto de línea
	.data
#structMat mat1 {
#  6,
#  6,
#  {
#    11.11, 12.12, 13.13, 14.14, 15.15, 16.16,
#    21.21, 22.22, 23.23, 24.24, 25.25, 26.26,
#    31.31, 32.32, 33.33, 34.34, 35.35, 36.36,
#    41.41, 42.42, 43.43, 44.44, 45.45, 46.46,
#    51.51, 52.52, 53.53, 54.54, 55.55, 56.56,
#    61.61, 62.62, 63.63, 64.64, 65.65, 66.66
#  }
#};
mat1:	.word	6
	.word	6
	.float	11.11, 12.12, 13.13, 14.14, 15.15, 16.16,
	.float	21.21, 22.22, 23.23, 24.24, 25.25, 26.26,
	.float	31.31, 32.32, 33.33, 34.34, 35.35, 36.36,
	.float	41.41, 42.42, 43.43, 44.44, 45.45, 46.46,
	.float	51.51, 52.52, 53.53, 54.54, 55.55, 56.56,
	.float	61.61, 62.62, 63.63, 64.64, 65.65, 66.66

#structMat mat2 {
#  7,
#  10,
#  {
#    -36.886, -58.201,  78.671,  19.092, -50.781,  33.961, -59.511, 12.347,  57.306,  -1.938,
#    -86.858, -81.852,  54.623, -22.574,  88.217,  64.374,  52.312, 47.918, -83.549,  19.041,
#     4.255, -36.842,  82.526,  27.394,  56.527,  39.448,  18.429, 97.057,  76.933,  14.583,
#    67.79 ,  -9.861, -96.191,  32.369, -18.494, -43.392,  39.857, 80.686, -36.87 , -17.786,
#    30.073,  89.938,  -6.889,  64.601, -85.018,  70.559, -48.853, -62.627, -60.147,  -5.524,
#    84.323, -51.718,  93.127, -10.757,  32.119,  98.214,  69.471, 73.814,   3.724,  57.208,
#    -41.528, -17.458, -64.226, -71.297, -98.745,   7.095, -79.112, 33.819,  63.531, -96.181
#  }
#};
mat2:	.word	7
	.word	10
	.float	-36.886, -58.201,  78.671,  19.092, -50.781,  33.961, -59.511, 12.347,  57.306,  -1.938,
	.float	-86.858, -81.852,  54.623, -22.574,  88.217,  64.374,  52.312, 47.918, -83.549,  19.041,
	.float	4.255, -36.842,  82.526,  27.394,  56.527,  39.448,  18.429, 97.057,  76.933,  14.583,
	.float	67.79 ,  -9.861, -96.191,  32.369, -18.494, -43.392,  39.857, 80.686, -36.87 , -17.786,
	.float	30.073,  89.938,  -6.889,  64.601, -85.018,  70.559, -48.853, -62.627, -60.147,  -5.524,
	.float	84.323, -51.718,  93.127, -10.757,  32.119,  98.214,  69.471, 73.814,   3.724,  57.208,
	.float	-41.528, -17.458, -64.226, -71.297, -98.745,   7.095, -79.112, 33.819,  63.531, -96.181

# structMat mat3 {
#   1,
#   8,
#   {
#     -36.52,  35.3 ,  79.05, -58.69, -55.23, -19.44, -88.63, -93.61
#   }
# };
mat3:	.word	1
	.word	8
	.float	-36.52,  35.3 ,  79.05, -58.69, -55.23, -19.44, -88.63, -93.61

# structMat mat4 {
#   16,
#   1,
#   { -90.57, -65.11, -58.21, -73.23, -89.38, -79.25,  16.82,  66.3 ,
#     -96.14, -97.16, -24.66,   5.27, -33.5 , -13.09,  27.13, -74.83 }
# };
mat4:	.word	16
	.word	1
	.float	-90.57, -65.11, -58.21, -73.23, -89.38, -79.25,  16.82,  66.3
	.float	-96.14, -97.16, -24.66,   5.27, -33.5 , -13.09,  27.13, -74.83

# structMat mat5 {
#   1,
#   1,
#   { 78.98 }
# };
mat5:	.word	1
	.word	1
	.float	78.98

# structMat mat6 {
#   0,
#   0,
#   { 0 }
# };
mat6:	.word	0
	.word	0
	.float	0.0

#float infinito = INFINITY;
infinito:	.word	0x7F800000

# Cadenas de caracteres
str_titulo:	.asciiz	"\nComienza programa manejo matrices con funciones\n"
str_menu:	.ascii	"(0) Terminar el programa\n"
		.ascii	"(1) Cambiar la matriz de trabajo\n"
		.ascii	"(3) Cambiar el valor de un elemento\n"
		.ascii	"(4) Intercambiar un elemento con su opuesto\n"
		.ascii	"(7) Encontrar el minimo\n"
		.asciiz	"\nIntroduce opción elegida: "
str_errorOpc:	.asciiz	"Error: opcion incorrecta\n"
str_termina:	.asciiz	"\nTermina el programa\n"
str_elijeMat:	.asciiz	"\nElije la matriz de trabajo (1..6): "
str_numMatMal:	.asciiz	"Numero de matriz de trabajo incorrecto\n"
str_errorFil:	.asciiz	"Error: dimension incorrecta.  Numero de fila incorrecto\n"
str_errorCol:	.asciiz	"Error: dimension incorrecta.  Numero de columna incorrecto\n"
str_indFila:	.asciiz	"\nIndice de fila: "
str_indCol:	.asciiz	"Indice de columna: "
str_nuevoValor:	.asciiz	"Nuevo valor para el elemento: "
str_valMin:	.asciiz	"\nEl valor minimo esta en ("
str_conValor:	.asciiz	") con valor "

str_matTiene:	.asciiz	"\n\nLa matriz tiene dimension "



	.text

	
# void print_mat(structMat* mat) {
print_mat:
# store the values in the stack
	addi $sp, -20
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $s3, 12($sp)
	sw $s4, 16($sp)

	# s0 -> nfil
	# s1 -> ncol
	# s2 -> elem
	# s3 -> fila
	# s4 -> columna

	lw $s0, nFil($a0) #   int nFil = mat->nFil;
	lw $s1, nCol($a0) #  	int nCol = mat->nCol;
	la $s2, elementos($a0) #   float* elem = mat->elementos;

#   std::cout << "\n\nLa matriz tiene dimension " << nFil << 'x' << nCol << '\n';
	li $v0, 4
	la $a0, str_matTiene
	syscall
	li $v0, 1
	move $a0, $s0
	syscall 
	li $v0, 11
	li $a0, 'x'
	syscall
	li $v0, 1
	move $a0, $s1
	syscall 
	li $v0, 11
	li $a0, LF
	syscall

	li $s3, 0
#   for(int f = 0 ; f < nFil; f++) {
bucle1_print_mat:
	bge	$s3, $s0, fin_bucle1_print_mat

#     for(int c = 0; c < nCol; c++) {
	li $s4, 0
bucle2_print_mat:
	bge $s4, $s1, fin_bucle2_print_mat

#       std::cout << elem[f*nCol + c] << ' ';
	lwc1 $f12, 0($s2)

	li $v0, 2
	syscall
	li $v0, 11
	li $a0, ' '
	syscall
#     }

	addi $s2, sizeF
	addi $s4, 1
	b bucle2_print_mat
fin_bucle2_print_mat:
#     std::cout << '\n';
	li $v0, 11
	li $a0, LF
	syscall
#   }

	addi $s3, 1
	b bucle1_print_mat
fin_bucle1_print_mat:
#   std::cout << '\n';
	li $v0, 11
	li $a0, LF
	syscall
# }
	#restore the values
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	lw $s4, 16($sp)
	addi $sp, 20

	jr $ra
print_mat_fin:


# void change_elto(structMat* mat, int indF, int indC, float valor) {
change_elto:

# a0 -> mat
# a1 -> indF
# a2 -> indC
# f12 -> valor

	lw $t1, nCol($a0)	#   int numCol = mat->nCol;
#   mat->elementos[indF * numCol + indC] = valor;
	mul $t0, $a1, $t1
	add $t0, $t0, $a2
	mul $t0, $t0, sizeF
	
	la $t5, elementos($a0)
	add $t5, $t0, $t5
	swc1 $f12, 0($t5)

	jr $ra
change_elto_fin:

# void swap(float* e1, float* e2) {
swap:
# Carga los valores de punto flotante de las direcciones de memoria
  lwc1 $f4, 0($a0)  # temp1 = *e1
  lwc1 $f5, 0($a1)  # temp2 = *e2
  swc1 $f5, 0($a0)  # *e1 = temp2
  swc1 $f4, 0($a1)  # *e2 = temp1

	jr $ra
swap_fin:


# void intercambia(structMat* mat, int indF, int indC) {
intercambia:

# a0 -> mat
# a1 -> indF
# a2 -> indC

	lw $t0, nCol($a0)	#   int numCol = mat->nCol;
	lw $t1, nFil($a0) #   int numFil = mat->nFil;
	la $t2, elementos($a0) #   float* datos = mat->elementos;
#   float* e1 = &datos[indF * numCol + indC];
	mul $t3, $a1, $t0
	add $t3, $t3, $a2
	mul $t3, $t3, sizeF

	add $t3, $t2, $t3
	move $a0, $t3

#   float* e2 = &datos[(numFil - indF - 1) * numCol + (numCol - indC - 1)];
	sub $t3, $t1, $a1
	addi $t3, -1
	mul $t3, $t0, $t3
	add $t3, $t3, $t0
	sub $t3, $t3, $a2,
	addi $t3, -1
	mul $t3, $t3, sizeF

	add $t3, $t3, $t2
	move $a1, $t3

#   swap(e1, e2);
	addi $sp, -4
	sw $ra, 0($sp)
	jal swap
	lw $ra, 0($sp)
	addi $sp, 4
# }
	jr $ra
intercambia_fin:


# std::tuple<float, int, int> find_min(structMat* mat) {
find_min:
	lw $t0, nCol($a0) #   int numCol = mat->nCol;
	lw $t1, nFil($a0) #   int numFil = mat->nFil;
	la $t2, elementos($a0) #   float* datos = mat->elementos;

	l.s $f4, infinito	#   float min = infinito;
	li $t3, -1	#   int fmin = -1;
	li $t4, -1	#   int cmin = -1;

#   for(int f = 0; f < numFil; f++) {
	li $t5, 0 # f = 0
bucle1_for_find_min:
	bge $t5, $t1, bucle1_for_find_min_fin

#     for(int c = 0; c < numCol; c++) {
	li $t6, 0 # c = 0
bucle2_for_find_min:
	bge $t6, $t0, bucle2_for_find_min_fin

#       float valor = datos[f * numCol + c];
	l.s $f6, 0($t2)
#       if (valor < min) {
if_find_min:
	c.lt.s $f6, $f4
	bc1f if_find_min_fin

	mov.s $f4, $f6	#         min = valor;
	move $t3, $t5		#         fmin = f;
	move $t4, $t6 	#         cmin = c;
#       }
if_find_min_fin:

#     }
	add $t2, sizeF
	addi $t6, 1
	b bucle2_for_find_min
bucle2_for_find_min_fin:
#   }
	addi $t5, 1
	b bucle1_for_find_min
bucle1_for_find_min_fin:

#   return {min, fmin, cmin};
	mov.s $f0, $f4  # Guarda 'min' en la dirección de memoria apuntada por $a0
  move $v0, $t3    # Guarda 'fmin' en la dirección de memoria apuntada por $a1
  move $v1, $t4    # Guarda 'cmin' en la dirección de memoria apuntada por $a2
# }
	jr $ra
find_min_fin:



# int main() {
main:

	# s0 -> matTrabajo
	# s1 -> opcion
	# s2 -> matT
	# s3 -> indFil
	# s4 -> indCol
	# f20 -> valorMin;
	# s6 -> filaMin;
	# s7 -> columnaMin;

#   std::cout << std::fixed << std::setprecision(8);  // Ignorar
#   std::cout << "\nComienza programa manejo matrices con funciones\n";
	li $v0, 4
	la $a0, str_titulo
	syscall

	la $s0, mat1	#   structMat* matTrabajo = &mat1;
#   while(true) {
while_true:

#     print_mat(matTrabajo);
	move $a0, $s0
	jal	print_mat

#     std::cout <<
#     "(0) Terminar el programa\n"
#     "(1) Cambiar la matriz de trabajo\n"
#     "(3) Cambiar el valor de un elemento\n"
#     "(4) Intercambiar un elemento con su opuesto\n"
#     "(7) Encontrar el minimo\n"
#     "\nIntroduce opción elegida: ";
	li $v0, 4
	la $a0, str_menu
	syscall
#     int opcion;
#     std::cin >> opcion;
	li $v0, 5
	syscall
	move $s1, $v0

#     if(opcion == 0) {
#       break;
#     }
	li $t0, 0
	beq $s1, $t0, while_true_fin

#     // Opción 1 ////////////////////////////////////////////////////////////
#     if(opcion == 1) {
opcion_1:
	li $t0, 1
	bne $s1, $t0, opcion_3_4
#       std::cout << "\nElije la matriz de trabajo (1..6): ";
	li $v0, 4
	la $a0, str_elijeMat
	syscall
#       int matT;
#       std::cin >> matT;
	li $v0, 5
	syscall
	move $s2, $v0
#       if (matT == 1) {
#         matTrabajo = &mat1;
#         continue;  // volvemos al principio del bucle
#       }
case_mat_1:
	li $t0, 1
	bne $s2, $t0, case_mat_2
	la $s0, mat1
	b while_true

#       if (matT == 2) {
#         matTrabajo = &mat2;
#         continue;  // volvemos al principio del bucle
#       }
case_mat_2:
	li $t0, 2
	bne $s2, $t0, case_mat_3
	la $s0, mat2
	b while_true

#       if (matT == 3) {
#         matTrabajo = &mat3;
#         continue;  // volvemos al principio del bucle
#       }
case_mat_3:
	li $t0, 3
	bne $s2, $t0, case_mat_4
	la $s0, mat3
	b while_true

#       if (matT == 4) {
#         matTrabajo = &mat4;
#         continue;  // volvemos al principio del bucle
#       }
case_mat_4:
	li $t0, 4
	bne $s2, $t0, case_mat_5
	la $s0, mat4
	b while_true

#       if (matT == 5) {
#         matTrabajo = &mat5;
#         continue;  // volvemos al principio del bucle
#       }
case_mat_5:
	li $t0, 5
	bne $s2, $t0, case_mat_6
	la $s0, mat5
	b while_true

#       if (matT == 6) {
#         matTrabajo = &mat6;
#         continue;  // volvemos al principio del bucle
#       }
case_mat_6:
	li $t0, 6
	bne $s2, $t0, case_mat_incorrecta
	la $s0, mat6
	b while_true

#       std::cout << "Numero de matriz de trabajo incorrecto\n";
#       continue;  // volvemos al principio del bucle
#     }
	li $v0, 4
	la $a0, str_numMatMal
	syscall
	b while_true

case_mat_incorrecta:
	li $v0, 4
	la $a0, str_numMatMal
	syscall

	b while_true


#     // Opción 3  y  4 //////////////////////////////////////////////////////////
#     if(opcion == 3 || opcion == 4) {
opcion_3_4:
	li $t0, 3
	beq $s1, $t0, comienzo_codigo
	li $t1, 4
	bne $s1, $t1, opcion_7 

comienzo_codigo:
#       std::cout << "\nIndice de fila: ";
	li $v0, 4
	la $a0, str_indFila
	syscall

#       int indFil;
#       std::cin >> indFil;
	li $v0, 5
	syscall
	move $s3, $v0

#       if ((indFil < 0) || (indFil >= matTrabajo->nFil)) {
	bltz $s3, if_fila
	lw $t0, nFil($s0)
	bge $s3, $t0, if_fila
	b if_fila_fin

#         std::cerr << "Error: dimension incorrecta.  Numero de fila incorrecto\n";
#         continue;  // volvemos al principio del bucle
#       }
if_fila:
	li $v0, 4
	la $a0, str_errorFil
	syscall
	b while_true

if_fila_fin:

#       std::cout << "Indice de columna: ";
#       int indCol;
#       std::cin >> indCol;
	li $v0, 4
	la $a0, str_indCol
	syscall
	li $v0, 5
	syscall
	move $s4, $v0

#       if ((indCol < 0) || (indCol >= matTrabajo->nCol)){
#         std::cerr << "Error: dimension incorrecta.  Numero de columna incorrecto\n";
#         continue;  // volvemos al principio del bucle
#       }
	bltz $s4, if_col
	lw $t0, nCol($s0)
	bge $s4, $t0, if_col
	b if_col_fin

if_col:

	li $v0, 4
	la $a0, str_errorCol
	syscall
	b while_true

if_col_fin:
	li $t0, 4
	beq $s1, $t0, opcion_4
#       if (opcion == 3) {
#         std::cout << "Nuevo valor para el elemento: ";
	li $v0, 4
	la $a0, str_nuevoValor
	syscall

#         float valor;
#         std::cin >> valor;
#         change_elto(matTrabajo, indFil, indCol, valor);
	li $v0, 6
	syscall
	move $a0, $s0
	move $a1, $s3
	move $a2, $s4
	mov.s $f12, $f0
	jal change_elto

#       }
	b while_true

#       if(opcion == 4) {
opcion_4:
#         intercambia(matTrabajo, indFil, indCol);


	move $a0, $s0
	move $a1, $s3
	move $a2, $s4
	jal intercambia

#       continue;
	b while_true
#     // Opción 7 ////////////////////////////////////////////////////////////
opcion_7:
	li $t0, 7
	bne $s1, $t0, opcion_incorrecta 
#     if(opcion == 7) {

#       float valorMin;
#       int filaMin;
#       int columnaMin;
#       std::tie(valorMin, filaMin, columnaMin) = find_min(matTrabajo);
#       std::cout << "\nEl valor minimo esta en (" << filaMin << ','
#         << columnaMin <<") con valor " << valorMin;
	move $a0, $s0
	jal find_min

	mov.s $f20, $f0 #       float valorMin; 
	move $s6, $v0 #       int filaMin;
	move $s7, $v1 #       int columnaMin;

	li $v0, 4
	la $a0, str_valMin
	syscall

	li $v0, 1
	move $a0, $s6
	syscall

	li $v0, 11
	la $a0, ','
	syscall

	li $v0, 1
	move $a0, $s7
	syscall

	li $v0, 4
	la $a0, str_conValor
	syscall

	li $v0, 2
	mov.s $f12, $f20
	syscall

#       continue;
#     }
	b while_true
#     // Opción Incorrecta ///////////////////////////////////////////////////////
opcion_incorrecta:
#     std::cout << "Error: opcion incorrecta\n";
	li $v0, 4
	la $a0, str_errorOpc
	syscall

	b while_true
while_true_fin:

#   std::cout << "\nTermina el programa\n";
	li $v0, 4
	la $a0, str_termina
	syscall
	li $v0, 10
	syscall
# }