
data segment
arr db 01h, 03h, 06h, 08h, 09h, ?
ele db 04h
count equ 6
data ends

code segment
assume cs:code, ds:data
start: mov ax, data
mov ds, ax
lea si, arr
mov cl, count
mov ah, ele
l2:cmp [si], ah
jl l1
xchg ah, [si]
l1: inc si
loop l2
mov arr+count-1, ah
mov ah, 4ch
int 21h
code ends
end start
