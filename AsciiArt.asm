	.data

sourceName: .asciiz "chat.pgm"
outputFile: .asciiz "AsciiChat.txt"
buffer:     .space 1

	.text
	
	
	#ouverture du fichier source en lecture seule
	ori $v0,$zero,13
	la $a0,sourceName
	ori $a1,$zero,0
	ori $a2,$zero, 0
	syscall
	add $s0,$v0,$zero 
	
	#ouverture du fichier de sortie en écriture
	ori $v0,$zero,13
	la $a0,outputFile
	ori $a1,$zero,1
	ori $a2,$zero, 0
	syscall
	add $s1,$v0,$zero
	
	
	jal lectureFichier
	#jal lectureFichier


lectureFichier:
	#Prologue
	addiu $sp,$sp,-8
	sw $ra,0($sp)
	sw $fp,4($sp)
	addiu $fp,$sp,8
	
	#Initialisation des registres qui permettront la reconstitution des nombres lus
	ori $t0,$zero,0
	ori $t1,$zero,10
	
tantQue : #tant que le caractère lu n'est pas un espace ou un '\n' on continue à lire un caractèredans le fichier
	
	#lecture d'un caractère
	ori $v0,$zero,14
	ori $a0,$s0,0    #lien du fichier que nous lisons
	la $a1,buffer	 #variable stockant la valeurs lue
	ori $a2,$zero,1  #nombre de caractères lus
	syscall
	
	#on regarde maintenant si ce n'est pas un espace ou '\n'
	lb $t7,buffer
	ori $t3,$zero,'\n'
	beq $t7,$t3,suitefonction
	ori $t3,$zero,' '
	beq $t7,$t3,suitefonction
	
	#arrivé ici, le caractère lu est un chiffre, on reconstitue donc le nombre
	#exemple : pour lire le nombre 15, on a d'abord lu 1 puis 5, pour faire 15 on fait : 1*10+5
	mult $t0,$t1
	mflo $t0
	add $t0,$t0,$t7
	j tantQue
	
suitefonction :
	#Affichage du nombre
	ori $v0,$zero,1
	ori $a0,$t0,0
	syscall
	
	#Epilogue
	lw $ra,0($sp)
	lw $fp,4($sp)
	addiu $sp,$sp,8
	jr $ra
	#fermeture des fichiers
	ori $v0,$zero,16
	ori $a0,$s0,0
	syscall
	
	ori $v0,$zero,16
	ori $a0,$s1,0
	syscall
	
	#exit
	ori $v0,$zero,10
	syscall























