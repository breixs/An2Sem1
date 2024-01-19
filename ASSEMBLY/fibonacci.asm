.model small
.data
NR1 DB 0 
NR2 DB 1
NR3 DB 0
                                                                                                                                                                                                                 ;:)
.code
main proc
    MOV AX, @data
    MOV DS,AX
    
    MOV AH,2
    MOV DL,NR1
    INT 21H;afis 0
    
    MOV AH, 2
    MOV DL,NR2
    INT 21H;afis 1 
    
    MOV AL, NR1;0+
    ADD AL, NR2;1=
    MOV NR3, AL;1
    MOV AH, 2
    MOV DL, NR3
    INT 21H ;afisare 1?
    
    MOV AL, NR2 ;1+
    ADD AL, NR3 ;1=
    MOV NR1, AL ;2
    MOV AH, 2
    MOV DL, NR1                                                                                                
    INT 21H ;afisare 2?
    
    MOV AL, NR1;2+
    ADD AL, NR3;1=
    MOV NR2, AL;3
    MOV AH, 2
    MOV DL, NR2
    INT 21H ;afisare 3?
    
    MOV AL, NR2;3+
    ADD AL, NR1;2=
    MOV NR3, AL;5 
    MOV AH, 2
    MOV DL, NR3
    INT 21H ;afisare 5?
    
    MOV AL, NR3;5
    ADD AL, NR2;3
    MOV NR1, AL;8
    MOV AH, 2
    MOV DL, NR1
    INT 21H ;afisare 8?
   main endp
end
    
    
    
    
    
    
    
    


        
     