data segment
a dw 0fcd2h, 3c54h
b dw 45f4h, 0bfe1h
c dw ?, ?, ?, ?
data ends
code segment
assume cs:code, ds: data
start: mov ax, data
mov ds, ax
mov ax, a
mul b; multiplication of q0 and m0
mov c, ax
mov bx, dx
mov ax, a+2
mul b;  multiplication of q1 and m0
add bx, ax
adc dx, 0000h
mov cx, dx
mov ax, a
mul b+2; multiplication of q0 and m1
add bx, ax
adc cx, dx
mov c+2, bx
mov ax, a+2
mul b+2; multiplication of q1 and m1
;adc dx, 0000h
add cx, ax
adc dx, 0000h
mov c+4, cx
mov c+6, dx
mov ah, 4ch
int 21h
code ends
end start

