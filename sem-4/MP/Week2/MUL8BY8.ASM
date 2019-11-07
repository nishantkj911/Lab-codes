data segment
a db 0Eh
b db 09h
c dw ?
data ends
code segment
assume cs:code, ds:data
start: mov ax, data
mov ds, ax
mov ah, 00h
mov al, a
mul b
mov c, ax
mov ah, 4ch
int 21h
code ends
end start
