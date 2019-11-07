data segment
baseadd equ 0ef40h
pa equ baseadd + 00
pb equ baseadd + 01
pc equ baseadd + 02
cnt equ baseadd + 03

data ends

code segment
assume cs:code, ds:data
start:  mov ax, data
        mov ds, ax

        mov dx, cnt
        mov al, 80h
        out dx, al

up2:   mov dx, pb
       mov al, 00h
up:    out dx, al
        inc al
        cmp al, 0ffh
        jnz up
        mov al,0ffh
up1:    out dx, al
        dec al
        cmp al, 00h

        jnz up1


        jmp up2

        mov ah, 4ch
        int 21h

code ends
end start
