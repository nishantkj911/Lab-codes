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
up2:    mov cl, 03fh

        mov al, 7fh
up:     out dx, al
        loop up

up3:    inc al
        out dx, al
        cmp al, 0ffh
        jnz up3

        mov al, 0ffh
up4:    out dx, al
        dec al
        cmp al, 07fh
        jnz up4

        mov cl, 03fh
up5:    mov al, 07fh
        out dx, al
        loop up5

        mov cl, 0ffh
        mov al,00h
up1:    out dx, al
        loop up1

        jmp up2

        mov ah, 4ch
        int 21h

code ends
end start
