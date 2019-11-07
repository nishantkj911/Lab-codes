data segment
a dw 0098h
b db 0Fh
c db ?, ?
data ends
code segment
assume cs:code, ds:data
start: mov ax, data
mov ds, ax
mov ax, a
div b
mov c, al
mov c+1, ah
mov ah, 4ch
int 21h
code ends
end start

