data segment
a dw 3
b dw 10
c db 2
pri dw ?
data ends

code segment
assume cs:code, ds:data
start:  mov ax, data
        mov ds, ax

        lea si, a
        lea di, b
        lea bp, pri
        mov ax, [si]
        mov bx, [di]
        mov dx, 0002
l1:     cmp dx, [si]
        jz l3
        div dl
        cmp ah, 00h
        jz j4
        inc dl
        jmp l1
l3:     mov [bp], dl
        inc bp
j4:     mov ax, [si]
        inc ax
        mov [si], ax
        cmp ax, bx
        je exit
        mov dl, c
        jmp l1

exit:   mov ah, 4Ch
        int 21h
        code ends
        end start


