data segment
a db 48
b db 91
c db 01011010b
d db 01001001b
e db 6253o
f db 7712o
ansd db ?
anso db ?
ansb db ?
data ends
code segment
assume cs: code, ds: data
start: mov ax, data
mov ds, ax
mov bl, a
mov bh, b
mov cl, c
mov ch, d
mov dl, e
mov dh, f
add bh, bl
add ch, cl
add dh, dl
mov ansd, bh
mov ansb, ch
mov anso, dh
mov ah, 4ch
int 21h
code ends
end start
