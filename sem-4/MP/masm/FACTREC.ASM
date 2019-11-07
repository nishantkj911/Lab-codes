data segment
num dw ?
fact dw ?
data ends

code segment
assume cs:code, ds:data
start:  mov ax, data
        mov ds, ax

        mov ah, 01h
        int 21h
        sub al, 30h
        mov byte ptr num, al

        mov ax, 1
        mov bx, num

        call factproc

        mov fact, ax

        mov ah, 4ch
        int 21h




factproc proc near

cmp bx, 0
jne l1
ret

l1:     mul bx
        dec bx
        call factproc
        ret

factproc endp

code ends
end start
