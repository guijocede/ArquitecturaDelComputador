.data
	message: .asciiz "Ingrese un numero: "
	resultado: .asciiz "El resultado es: "
.text
.globl main
	main:
		li $v0, 4
		la $a0, message
		syscall
		
		li $v0, 5
		syscall
		
		move $a0, $v0
		
		#li $v0, 1
		#addi $a0, $a0, 0 
		#syscall

		jal sum
		
		li $v0, 4
		la $a0, resultado
		syscall
		
		li $v0, 1
		move $a0, $t0
		syscall
		
	exit:
		li $v0, 10
		syscall
		
	sum:
		beq $a0, $zero, sum_exit
		add $a1, $a1, $a0
		addi $a0, $a0, -1
		j sum
		
		sum_exit:
			add $t0, $a1, $zero
			jr $ra		