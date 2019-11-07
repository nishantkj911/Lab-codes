data segment
x dw 0947h
y dw 0F1c2h
z dw 0441h
res dw ?
data ends

code segment
assume cs:code, ds:data
start:  mov ax, data
        mov ds, ax

        addm macro num1, num2, result
        mov ax, num1
        mov bx, num2
        add ax, bx
        mov result, ax
        endm

        subm macro num1, num2, result
        mov ax, num1
        mov bx, num2
        sub ax, bx
        mov result, ax
        endm

        addm x, y, res
        subm y, z, res

        mov ah, 4ch
        int 21h

        code ends
        end start
