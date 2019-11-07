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

        
        mov dx, pb
up2:    mov cl, 0ffh
        mov al, 0ffh
up:     out dx, al
        loop up

        mov cl, 0ffh
        mov al,00h
up1:    out dx, al
        loop up1

        jmp up2

        mov ah, 4ch
        int 21h

code ends
end start
