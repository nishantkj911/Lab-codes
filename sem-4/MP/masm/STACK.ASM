stck segment stack
dw 50 dup(0)
tos label word
stck ends

code segment
assume cs:code, ss:stck
start:  mov ax, stck
        mov ss, ax
        mov sp, offset tos

        mov ax, 0010h
        mov bx, 921Fh
        push ax
        push bx

        add ax, bx
        pop bx
        pop cx

        mov ah, 4ch
        int 21h

        code ends
        end start


