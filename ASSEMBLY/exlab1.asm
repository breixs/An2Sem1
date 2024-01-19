.model small
.data
A DB 0
B DB 0
C DB 0
X DW 0

.code
main proc
    MOV AX, @data
    MOV DS,AX
    
    MOV AH, 1
    INT 21H
    MOV A, AL
    
    MOV AH, 1
    INT 21H
    MOV B, AL
    
    MOV AH, 1
    INT 21H
    MOV B, AL
    
    MOV AH, 1
    INT 21H
    MOV C, AL
    
    MOV AL,A
    ADD AL,B
    SUB AL,C
    
    MOV AH,2
    MOV DL,AL
    INT 21H
    main endp
end
    
    
    



