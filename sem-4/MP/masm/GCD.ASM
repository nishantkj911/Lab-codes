data segment
a dw 96d
b db 72d
c db ?
data ends
code segment
assume cs:code, ds:data
start: mov ax, data
mov ds, ax
mov ax, a
mov bl, b
div bl
l1:
mov al, bl
mov bl, ah
mov ah, 00h
div bl
cmp ah, 00h
jnz l1
mov c, bl
mov ah, 4ch
int 21h
code ends
end start

