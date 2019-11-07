data segment
n db 40
m db 70
arr db 30 dup(0)
data ends

;NOT WORKING
code segment
assume cs:code, ds:data
start:  mov ax, data
        mov ds, ax

        mov al, n
        mov dh, n
        mov ah, 00h
        lea si, arr

l1:  mov bl, 02h
prime:  div bl
        cmp ah, 00h
        jz exipr
        inc bl
        mov ah, 00h
        mov al, dh
        cmp bl, dh
        jnz prime

        mov [si], dh
        inc si
exipr:  inc dh
        cmp dh, m
        jnz l1

mov ah, 4Ch
int 21h
code ends
end start
