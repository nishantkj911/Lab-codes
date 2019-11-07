data segment
arr db 19h, 98h, 22h, 15h, 0ach, 10h, 29h
pos db 03h
n db 07h
data ends

code segment
assume cs:code, ds:data
start: mov ax, data
mov ds, ax
lea bx, arr
lea di, arr
add di, word ptr n
dec di
add bl, pos
dec bx
l1:     mov al, [bx+1]
        mov [bx], al
        inc bx
        cmp bx, di
        jne l1
mov al, 00h
mov [bx], al
mov ah, 4ch
int 21h
code ends
end start
