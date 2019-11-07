data segment
baseadd equ 0e0c0h
pa equ baseadd + 00
pb equ baseadd + 01
pc equ baseadd + 02
cntrl equ baseadd + 03
data ends

code segment
assume cs:code, ds:data
start:  mov ax, data
        mov ds, ax

        mov dx, cntrl
        mov al, 8ah
        out dx, al

        mov al, 80h

rpt:    mov dx, pa
        out dx, al
        
delay: mov si, 0fffh
l2:    mov cx, 0ffffh

lp:     loop lp
        dec si
        jnz l2

        ror al, 1
        mov ah, al

inp:    mov dx, pb
        in al, dx

        cmp al, 1
        jb inp

        mov al, ah
        jmp rpt


exit:   mov ah, 4ch
        int 21h

code ends
end start

