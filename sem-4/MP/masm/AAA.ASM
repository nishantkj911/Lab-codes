code segment
assume cs:code
start:
mov al, 38h
mov ah, 3Ah
add al, ah
mov ah, 00h
aaa

mov ah, 4ch
int 21h
code ends
end start

