.data
	endl: .asciiz "\n"


.text

addi $s0, $zero, 0 
addi $s1, $zero, 5 
addi $s2, $zero, 1 

FOR:
ble $s1, $s0, END
add $s2, $s2, $s0
addi $s0, $s0, 1
j FOR

END:
move $a0, $s1
li $v0, 1
syscall

la $a0, endl
li $v0, 4
syscall

move $a0, $s2
li $v0, 1
syscall

li $v0, 10
syscall