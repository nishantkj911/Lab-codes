data segment
a db 0b4h
b db 0fch
c db ?
data ends
code segment
assume cs:code, ds:data
start: mov ax,data
mov ds,ax
mov al,a
mov ah,b
sub al,ah
mov c,al
mov ah,4ch
int 21h
code ends
end start
