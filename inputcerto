.data
#=========MEMSAGENS===========#
    mem_inicio : .asciiz "\n\nESCOLHA SUA BEBIDA \nCafé puro (1)\nCafé com leite (2) \nMoccachino (3)"
    mem_EscTamanho : .asciiz "\n\nESCOLHA O TAMANHO \nPequeno (4)\nGrande (5)"
    mem_EscAcucar : .asciiz "\n\nGOSTARIA DE ACUCAR \nSim (6)\nNao (7)"
    memEscCafe : .asciiz "\nBEBIDA SELECIONADA : CAFE"
    memEscLeite : .asciiz "\nVOCE ESCOLHEU : CAFE COM LEITE"
    memEscMoca : .asciiz "\nVOCE ESCOLHEU : MOCA"
    memEscTamPeq:.asciiz "\nVOCE ESCOLHEU : TAMANHO PEQUENO"
    memEscTamGra:.asciiz "\nVOCE ESCOLHEU : TAMANHO GRANDE"
    memEscAcucarSim : .asciiz "\nVOCE ESCOLHEU : QUERO ACUCAR"
    memEscAcucarNao : .asciiz "\nVOCE ESCOLHEU : NAO QUERO ACUCAR"
#=============================#

#=========VARIAVEIS===========#
	
    dose : .word 4
    read_keyboard:   .word 0xFFFF0014
    line:            .word 0xFFFF0012

tabela_codigos:
    .byte 0x11,0x21,0x41,0x81
    .byte 0x12,0x22,0x42,0x82
    .byte 0x14,0x24,0x44,0x84
    .byte 0x18,0x28,0x48,0x88

tabela_valores:
    .byte 0,1,2,3
    .byte 4,5,6,7
    .byte 8,9,10,11
    .byte 12,13,14,15

.text
.globl main
main:

	#PRINTA MENSAGEM ESCOLHA SUA BEBIDA
	li 	      $v0, 4     
	la 	      $a0, mem_inicio    
	syscall

	
loop_principal:
    li  $s0, 0            # zera acumulador antes de nova entrada
coleta_loop:
    # --- rotina de leitura de tecla (varredura) ---
    lw  $t1, read_keyboard
    lw  $t0, line
    li  $t3, 1
lendo_teclado:
    sb  $t3, 0($t0)
    lb  $t4, 0($t1)
    bne $t4, $zero, tecla_detectada
    sll $t3, $t3, 1
    ble $t3, 8, lendo_teclado
    j   coleta_loop        # continua coletando
# --- tecla detectada: traduz para índice (0..15) ---
tecla_detectada:
    li  $t3, 0
    la  $t5, tabela_codigos
traduzir:
    lb  $t6, 0($t5)
    beq $t6, $t4, encontrou
    addi $t3, $t3, 1
    addi $t5, $t5, 1
    blt $t3, 16, traduzir
    j   coleta_loop        # não encontrada -> volta
encontrou:
    la  $t7, tabela_valores
    add $t7, $t7, $t3
    lb  $t9, 0($t7)        # t9 = valor 0..15

    # Se t9 == 10 (tecla 'A'), trata como ENTER
    li  $t8, 10
    beq $t9, $t8, terminou_coleta

    # Se t9 <= 9 -> é dígito decimal, acumula: s0 = s0*10 + t9
    li  $t6, 9
    ble $t9, $t6, acumula_decimal
    # Se for A-F mas não enter, ignora (ou trate como erro)
    j   espera_solta

acumula_decimal:
    # s0 = s0 * 10
    li  $t2, 10
    mul $s0, $s0, $t2    # pseudo-instr mul disponível no MARS
    addu $s0, $s0, $t9   # s0 += digit
    # (opcional) imprimir o dígito ecoado:
    li  $a0, '0'
    add $a0, $a0, $t9
    li  $v0, 11
    syscall

espera_solta:
    # espera liberação da tecla
    lb  $t4, 0($t1)
    bne $t4, $zero, espera_solta
    j   coleta_loop

terminou_coleta:
    # tecla ENTER detectada -> chama rotina para usar o número em $s0
    jal processa_num
    # após processar, volta para início e permite nova entrada
    j   loop_principal

# rotina de exemplo: processa_num (aqui apenas imprime inteiro no console)
processa_num:
   
    beq $s0 , 1 , cafe
    beq $s0 , 2 , leite
    beq $s0 , 3 , moca
    beq $s0 , 4 , pequeno
    beq $s0 , 5 , grande
    beq $s0 , 6 , acucarSim
    beq $s0 , 7 , acucarNao
     
    	
    jr $ra

cafe : 
	li 	      $v0, 4       #Comando
	la 	      $a0, memEscCafe    #Carrega string (endereço).
	syscall
	j escolherBebida
leite :
	li 	      $v0, 4       #Comando
	la 	      $a0, memEscLeite #Carrega string (endereço).
	syscall
	j escolherBebida
moca : 
	li 	      $v0, 4       #Comando
	la 	      $a0, memEscMoca    #Carrega string (endereço).
	syscall
	
escolherBebida: 
	li 	      $v0, 4     
	la 	      $a0, mem_EscTamanho   
	syscall
	
	j loop_principal
pequeno: 
	li 	      $v0, 4       #Comando
	la 	      $a0, memEscTamPeq
	syscall
	
	j escolherAcucar 	
grande: 
	li 	      $v0, 4       #Comando
	la 	      $a0, memEscTamGra
	syscall
escolherAcucar: 
	li 	      $v0, 4     
	la 	      $a0, mem_EscAcucar   
	syscall
	
	j loop_principal
	
acucarSim : 
	li 	      $v0, 4       #Comando
	la 	      $a0, memEscAcucarSim
	syscall
	
	j fim
	
acucarNao : 
	li 	      $v0, 4       #Comando
	la 	      $a0, memEscAcucarNao
	syscall
	
	
fim:
    li  $v0, 10                   # Código de saída
    syscall
