data segment
a dw 9489h, 41cfh
b dw 0154h, 0eab0h
c dw ?, ?, ?, ?
data ends
code segment
assume cs:code, ds:data
start: mov ax, data
mov ds, ax
mov ax, a
mul b
mov c, ax
mov c+2, dx

mov ax, a+2
mul b
add c+2, ax
mov c+4, dx
adc c+4, 0000h

mov ax, a
mul b+2
add c+2, ax
adc c+4, dx

mov ax, a+2
mul b+2
;adc dx, 0000h
add c+4, ax
mov c+6, dx
adc c+6, 0000h
mov ah, 4ch
int 21h
code ends
end start
