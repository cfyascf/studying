.data
	endl: .asciiz "\n"


.text
main:
	addi $s0, $zero, -5
	addi $s1, $zero, 1
	addi $s2, $zero, 120
while:
	blt $s2, $s1, end
	addi $s0, $s0, 1
	add $s1, $s1, $s0
	j while
end:
	move $a0, $s0
	li $v0, 1
	syscall
	
	la $a0, endl
	li $v0, 4
	syscall
	
	move $a0, $s1
	li $v0, 1
	syscall
	
	
	
	li $v0, 10
	syscall