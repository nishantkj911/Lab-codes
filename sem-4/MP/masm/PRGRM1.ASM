data segment
a dw 0fab4h
b db 0fch
data ends
code segment
assume cs:code, ds:data
start: mov ax, data
mov ds, ax
mov al, b
lea bx, b
mov ah, 4ch
int 21h
code ends
end start

