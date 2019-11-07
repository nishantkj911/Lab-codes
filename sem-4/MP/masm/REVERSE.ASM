data segment
str db 'reversestr$'
len db [$-str-1]
revstr db 30h dup(?)
data ends

code segment
assume cs:code, ds:data, es:data
start:  mov ax, data
        mov es, ax
        mov ds, ax

        mov cl, len
        lea si, str
        add si, word ptr len
        dec si
        lea di, revstr

l1:     mov al, [si]
        mov [di], al
        inc di
        dec si
        dec cl
        jnz l1

        mov al, '$'
        mov [di], al
mov ah, 4ch
int 21h
code ends
end start
