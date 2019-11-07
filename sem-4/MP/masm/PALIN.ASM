data segment
str db 'rdmpalinnilapmdr$'
len db [$-str-1]
palin db ?
data ends

code segment
assume cs:code, ds:data, es:data
start:  mov ax, data
        mov es, ax
        mov ds, ax

        lea si, str
        lea di, str
        add di, word ptr len
        dec di
l1:     mov al, [si]
        cmp al, [di]
        jne no
        inc si
        dec di
        cmp di, si
        jg l1

        mov al, 'Y'
        mov palin, al
        jmp exit

no:     mov al, 'N'
exit:   mov palin, al
        mov ah, 4Ch
        int 21h
        code ends
        end start
