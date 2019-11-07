data segment
arr dw -896d, -37d, -11d
n db 23d
ans dw ?, ?, ?
data ends

code segment
assume cs:code, ds:data
start: mov ax, data
        mov ds, ax
        lea si, arr
        lea di, ans
        ;mov ah, 00h
        mov ax, [si]
        idiv n
        mov [di], ax
        mov al, [si]
        mul n
        mov [di+1], ax
mov ah, 4ch
int 21h
code ends
end start
