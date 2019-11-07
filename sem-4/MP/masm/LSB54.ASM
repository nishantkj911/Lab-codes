data segment
str db "manipal$"
str1 db 10dup(0)
data ends

code segment
assume cs:code ds:data
start:mov ax,data
      mov ds,ax
      mov es,ax
      lea di,str
      lea si,str1
      mov al,'$'
  do:scasb
     jnz do
     dec di
     dec di
  go:mov al,[di]
     mov [si],al
     inc si
     dec di
     jnz go
     mov al,[di]
     mov [si],al
     inc si
     mov al,'$'
     mov [si],al
     mov ah,4ch
     int 21h
     code ends
     end start

