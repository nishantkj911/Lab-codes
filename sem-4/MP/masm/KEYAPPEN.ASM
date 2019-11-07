data segment
mssg1 db 'Enter the string: ', 0dh, 0ah, '$'
buffer db 64h, ?, 64h dup (0), '$'
mssg2 db 'nishdish.txt$'
error db 'An error occurred$'
fh dw ?
data ends

code segment
assume cs:code, ds:data
start:  mov ax, data
        mov ds, ax

        mov ah, 09h
        mov dx, offset mssg1
        int 21h

        mov ah, 0Ah
        mov dx, offset buffer
        int 21h

        mov ah, 3Dh
        mov al, 02h
        mov dx, offset mssg2
	int 21h
        jc err
        mov fh, ax

        mov ah, 42h
        mov bx, fh
        mov cx, 0000h
        mov dx, 0007h
        mov al, 00h
        int 21h
        jc err

        mov ah, 40h
        mov bx, fh
        mov cl, buffer+1
        mov dx, offset buffer+2
        int 21h
	jmp exit

err:    mov ah, 09h
        mov dx, offset error
        int 21h

exit:   mov ah, 4ch
        int 21h
        code ends
        end start
        
