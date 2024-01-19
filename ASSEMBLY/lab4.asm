.model small

.data
A DB 0
B DB 0
T DB 3 
D DB 2

N DB ?
M DB ?

.code

main proc
    MOV AX, @data
    MOV DS, AX
    
    MOV AH, 1
    INT 21H   
    SUB AL, 48
    MOV N, AL
    
    MOV AH, 1
    INT 21H
    SUB AL, 48
    MOV M, AL
    ;N
    MOV AL, N
    MUL T ;N*3
    
    ADD AL, 4 ;(N*3)+4
    
    SHR AL, 1; [(N*3)+4]/2
    MOV A, AL
     
    MOV AL, A
    ADD AL, 48
    
    MOV AH, 2
    MOV DL, AL
    INT 21H
      
    ;m
    MOV AL, M
    MUL D ;M*2
    INC AL;M+1
    
    SHR AL, 2 ;(M+1)/4
    MOV B, AL
    
    MOV AL, B
    ADD AL, 48
    
    MOV AH, 2
    MOV DL, AL
    INT 21H
    
    MOV AL, A
    MOV BH, B
    CMP AL, BH
    JS L1 ;b>a
    JZ L2;b=a
    MOV BL, A 
    JMP final
    L1: MOV BL, B
    JMP final
    L2: MOV BL, B
    final:nop
      
 main endp
end

    
    
    
    
    
    
    
    





