data segment
a dw 7821h, 1192h
b dw 2821h
c dw ?, ?
data ends
code segment
assume cs:code, ds: data
start: mov ax, data
mov ds, ax
mov ax, a
mov dx, a+2
div b
mov c, ax
mov c+2, dx
mov ah, 4ch
int 21h
code ends
end start
