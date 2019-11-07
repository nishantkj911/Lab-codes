data segment
arr db 0FBh, 0ACh, 0B9h, 0C9h
NIS dw 0acah, 0beb9h
dis dd 82bf641ah
data ends
code segment
assume cs:code, ds:data
start: mov ax, data
mov ds, ax
mov ax, 0607h
aad
mov arr, 05h
div arr
mov ah, 4ch
int 21h
code ends
end start
