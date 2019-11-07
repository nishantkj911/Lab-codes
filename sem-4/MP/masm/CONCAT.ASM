data segment
str1 db 'string $'
str2 db 'concatenation$'
totstr db 64h dup(?)
data ends

code segment
assume cs:code, ds:data, es:data
start:  mov ax, data
        mov ds, ax
        mov es, ax

        lea si, str1
        lea di, totstr
        mov al, '$'

con1:   cmp [si], al
        je con2
        movsb
        jmp con1

con2:   lea si, str2
loop2:  cmp [si], al
        je exit
        movsb
        jmp loop2
exit:   mov [di], al
mov ah, 4ch
int 21h
code ends
end start

