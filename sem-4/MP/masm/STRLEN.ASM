data segment
str db 'Nishant loves Dishari$'
len db ?
data ends

code segment
assume cs:code, ds:data, es:data
start: mov ax, data
mov ds, ax
mov es, ax

lea di, str
mov al, '$'
cld
l1:scasb
jne l1
dec di
mov word ptr len, di

mov ah, 4ch
int 21h
code ends
end start
