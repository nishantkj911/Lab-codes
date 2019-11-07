data segment
a dw 01b4h
b dw 00fch
c dw ?
data ends
code segment
assume cs:code, ds:data
start: mov ax,data
mov ds,ax
mov ax,a
mov bx,b
sub bx,ax
mov c,bx
mov ah,4ch
int 21h
code ends
end start
