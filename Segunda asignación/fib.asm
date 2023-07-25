.data

	prompt: .asciiz "Ingrese n: "
	br: .asciiz "\n"
	space: .asciiz " "
.text

	main:
	
		# Preguntar el valor de n
		li $v0, 4
		la $a0, prompt
		syscall
		
		# Leer el valor de n
		li $v0, 5
		syscall
		
		# Ingresar el valor de n dentro del registro $t0
		add $t0, $zero, $v0		
		
		# Inicializar mis variables	Fibonacci actual = a + b
		addi $t2, $zero, 0		# a
		addi $t3, $zero, 1		# b
		addi $t1, $zero, 1		# i 
		
		# Imprimo el primer valor de la sucesión
		li $v0, 1
		addi $a0, $zero, 1
		syscall
		
		while:
			
			# Establezco mi condición de salida $t1 = $t0  (  i = n  )
			beq $t1, $t0, exit
			
			# Imprimo un espacio entre cada número
			li $v0, 4
			la $a0, space
			syscall
			
			# Imprimo el número actual de la sucesión
			li $v0, 1
			add $a0, $t2, $t3
			syscall
			
			# Avanzo los valores de a y b
			add $t2, $zero, $t3
			add $t3, $zero, $a0
			
			# Incremento el valor de i ( i+1 )
			addi $t1, $t1, 1
			
			# Vuelvo al ciclo
			j while
			
		exit:
		
	# Fin del main
	li $v0, 10
	syscall