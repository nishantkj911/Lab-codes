data segment
bcd db 18h, 15h
asc dw ?, ?
count db 02
data ends
code segment
assume cs:code, ds:data
start: mov ax, data
mov ds, ax
mov cl, 4
lea si, bcd
lea di, asc
do:
mov al, [si]
mov bx, si
mov ah, 00h
rol ax, cl
add ax, 3030h
mov [di], ax
inc si
inc di
inc di
dec count
jnz do
mov ah, 4ch
int 21h
code ends
end start

