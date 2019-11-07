data segment
str db 'elementary$'
substr db 'men$'
present db ?
data ends

code segment
assume cs:code, ds:data, es:data
start:  mov ax, data
        mov ds, ax
        mov es, ax

        lea si, str
        lea di, substr
        mov al, '$'

l1:     cmpsb
        je subcmp
        lea di, substr
        cmp [si], al
        jne l1
        mov al, 'N'
        mov present, al
        jmp exit

subcmp: cmpsb
        jne l1
        cmp [di], al
        jne subcmp
        mov al, 'Y'
        mov present, al
exit:   mov ah, 4ch
int 21h
code ends
end start
