data segment
a dw 0A1E4h, 0510h
b dw 548Ah
c dw ?, ?, ?
data ends
code segment
assume cs:code, ds: data
start: mov ax, data
mov ds, ax
mov ax, a
mul b
mov c, ax
mov dx, bx
mov ax, a+2
mul b
add bx, ax
mov c+2, bx
adc dx, 0000h
mov c+4, dx
mov ah, 4ch
int 21h
code ends
end start
