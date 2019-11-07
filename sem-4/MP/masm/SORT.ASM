data segment
arr db 15h, 07h, 03h, 10h, 0c1h, 0F0h, 01ch
count db 06h
data ends

code segment
assume cs:code, ds:data
start: mov ax, data
mov ds, ax

mov dl, count
dec dl
l3:lea si, arr
mov cl, count
l2:mov al, [si]
cmp al, [si+1]
jle l1
xchg al, [si+1]
mov [si], al
l1: inc si
    loop l2
    dec dl
    jnz l3
mov ah, 4ch
int 21h
code ends
end start
