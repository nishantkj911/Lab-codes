code segment
assume cs:code
start:  mov ax, 0F1A9h
        xor ax, 8888h
mov ah, 4ch
int 21h
code ends
end start
