data segment
baseadd equ 0e0c0h
pa equ baseadd + 00
pb equ baseadd + 01
pc equ baseadd + 02
cntrl equ baseadd + 03
number db ?
comp db ?
data ends

code segment
assume cs:code, ds:data
start:  mov ax, data
        mov ds, ax

        mov dx, cntrl
        mov al, 8ah
        out dx, al

rpt:    mov dx, pb
        in al, dx
        mov number, al
        not al
        inc al

        mov dx, pa
        out dx, al
        jmp delay

dispff: mov dx, pa
        mov al, 0ffh
        out dx, al

delay: mov si, 0fffh
       mov cx, 0ffffh

lp:     loop lp
        dec si
        jnz lp

        mov ah, 0bh
        int 21h
        or al, al
        jz rpt


        mov ah, 4ch
        int 21h

code ends
end start

