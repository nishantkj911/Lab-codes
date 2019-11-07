data segment
arr db 7ch, 91h, 0abh, 19h, 82h, 23h, 0c5h, 0edh, 1ch, 0dfh
evenos db 0d
odd db 0d
grten db 0d
data ends

code segment
assume cs:code, ds:data
start:  mov ax, data
        mov ds, ax

        lea si, arr
        mov cl, 10d
l1:     mov al, [si]
        cmp al, 10d
        jle lbten
        inc grten
lbten:  and al, 01h
        cmp al, 00h
        jz eve
        inc odd
        jmp exit
eve:    inc evenos
        loop l1
exit:   mov ah, 4ch
int 21h
code ends
end start
