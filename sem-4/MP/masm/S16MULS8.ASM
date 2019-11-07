data segment
a dw 91edh
b db 7bh        
c db 3 dup(0)
data ends

code segment
assume cs:code, ds:data
start:  mov ax, data
        mov ds, ax

        mov al, byte ptr a
        imul b
        add word ptr c, ax

        mov al, byte ptr a+1
        imul b
        mov bl, ah
        ;cbw
        add word ptr c+1, ax
        adc c+2, bl
        add c+2, ah
                
mov ah, 4ch
int 21h
code ends
end start
