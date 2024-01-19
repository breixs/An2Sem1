.model small

.data
A DB 5;=>4
B DB 3;=>2
C EQU 1;=>1
D DB 4;=>3
FIN DB 0 
X DW 0x16h

;4-2-1+3=1+3=4 

.code 

main proc
    MOV AX, @data
    MOV DS,AX
    
    DEC A;4
    MOV AL, A;4
    DEC B;2
    NEG B;-2
    ADD AL, B;4-2=2
    MOV AH, C;1
    NEG AH; -1
    ADD AL, AH;2-1=1
    DEC D;3
    ADD AL, D;1+3=4
    MOV FIN, AL
    MOV AH,2
    MOV DL, FIN
    INT 21H;afisare cod ascii 
    main endp
end
        
    
    
    