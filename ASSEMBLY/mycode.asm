.model small
.data

var1 db 15
var2 db ?  
C EQU 9

.code

main proc 
    mov ax,@data
    mov ds,ax
    
    mov var2,C
    mov ah,var1
    mov al,var2
    
    mov var1,al
    mov var2,ah     
          
    main endp
end




