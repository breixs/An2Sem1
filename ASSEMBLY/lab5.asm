.model small

.data

C DB 101
;TEMP DB 0
VOC_A DB 97
VOC_E DB 101
VOC_I DB 105
VOC_O DB 111
VOC_U DB 117 
FIN DB 0

.code

main proc
    MOV AX, @data
    MOV DS, AX
    
    MOV AH, C
    ;MOV BL, AL
    MOV BH, AH
    
    SUB BH, VOC_A
    JZ L1
    MOV BH, AH
    
    SUB BH, VOC_E
    JZ L1
    MOV BH, AH
    
    SUB BH, VOC_I
    JZ L1
    MOV BH, AH
    
    SUB BH, VOC_O
    JZ L1
    MOV BH, AH 
    
    SUB BH, VOC_U
    JZ L1
    JMP final
     
    L1:SUB AH, 32
    MOV FIN, AH
    final:nop
    
    main endp
end
    
    




