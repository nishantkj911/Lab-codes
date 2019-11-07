data segment
a db 05h
b db 0Fh
c db ?
data ends
code segment
assume cs:code, ds:data
start: mov ax, data
mov ds,ax
mov al,a
mov ah,b
add ah,al
mov c,ah
mov ah, 4ch
int 21h
code ends
end start
