# Implementación del algoritmo de ordenamiento burbuja en MIPS 32
.data
array: .word 4, 1, 2, 3, 5    # Array de números desordenados
length: .word 5                  # Longitud del array
newline: .asciiz "\n"  
message: .asciiz "Array ordenado: "
messageF: .asciiz "Fin del Arreglo.\n" 
comma: .asciiz ", "

.text
.globl main

main:
    la $t0, array   
    lw $t1, length              # Cargar la longitud del array en $t1
    addi $t2, $zero, 1        # Cargar el indice del while en 1

loop1:
    addi $t0, $zero, 0            # Cargar la dirección base del array en $t0 
    bge   $t2, $t1, end1         # Si llego al final, salir del bucle             
    addi $t3, $zero, 1          # Inicializar el índice del primer elemento a comparar en 1

	loop2:
   		bge $t3, $t1, end2           # Si se llegó al final del array, salir del bucle interno
    		lw $t4, array($t0)               # Cargar el primer elemento a comparar en $t4
    		addi $t0, $t0, 4
    		lw $t5, array($t0)              # Cargar el segundo elemento a comparar en $t5
    		addi $t0, $t0, -4
    		ble $t4, $t5, next         # Si el primer elemento es menor o igual que el segundo, pasar al siguiente par de elementos
    		addi $t0, $t0, 4
    		sw $t4, array($t0)               # Intercambiar los elementos            
    		addi $t0, $t0, -4
    		sw $t5, array($t0)             
    
	next:
    		addi $t0, $t0, 4            # Avanzar al siguiente par de elementos            
    		addi $t3, $t3, 1            # Incrementar el índice del primer elemento a comparar
   		j loop2
   		
   	end2:	
   		addi $t2, $t2, 1
   		j loop1
    
end1:
	jal mostrar
	li $v0, 10
	syscall
    

# El array está ahora ordenado en orden ascendente    

# Imprimir el array ordenado 
mostrar:
la $t0, array                  # Cargar la dirección base del array en $t0
lw $t1, length                  # Cargar la longitud del array en $t1

li $v0, 4                       # Cargar el código de la llamada al sistema para imprimir una cadena    
la $a0, message                 # Cargar la dirección de la cadena de mensaje en $a0
syscall                         # Imprimir el mensaje "Array ordenado:"

li $v0, 4                       # Cargar el código de la llamada al sistema para imprimir una cadena    
la $a0, newline                 # Cargar la dirección de la cadena de nueva línea en $a0
syscall                         # Imprimir una nueva línea

addi $t7, $zero, 0              # Inicializar el índice del elemento a imprimir en 0    

loop3:
    bge $t7, $t1, end3          # Si se llegó al final del array, salir del bucle
    lw $t3, ($t0)               # Cargar el elemento a imprimir en $t3
    li $v0, 1                   # Cargar el código de la llamada al sistema para imprimir un entero
    move $a0, $t3               # Cargar el valor del elemento a imprimir en $a0        
    syscall                     # Imprimir el elemento
    
    li $v0, 4                   # Cargar el código de la llamada al sistema para imprimir una cadena
    la $a0, comma               # Cargar la dirección de la cadena de coma en $a0        
    syscall                     # Imprimir una coma
    
    addi $t0, $t0, 4            # Avanzar al siguiente elemento
    addi $t7, $t7, 1            # Incrementar el índice del elemento a imprimir        
    j loop3

end3:
    li $v0, 4                   # Cargar el código de la llamada al sistema para imprimir una cadena    
    la $a0, newline             # Cargar la dirección de la cadena de nueva línea en $a0
    syscall                     # Imprimir una nueva línea.
    
    li $v0, 4                       
    la $a0, messageF                 
    syscall                         

    li $v0, 4                     
    la $a0, newline             
    syscall
    
    jr $ra