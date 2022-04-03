; Simple print function for kernel
; Parameters :
;   - bx : string to print

print:
    pusha

print_loop:
    mov al, [bx]
    cmp al, 0
    je print_done
    mov ah, 0x0e                ; go to tty mode
    int 0x10                    ; interrupts CPU to print char in bx
    add bx, 1
    jmp print_loop

print_done:
    popa
    ret

print_newline:
    pusha
    mov ah, 0x0e
    mov al, 0x0a                ; newline char
    int 0x10
    mov al, 0x0d                ; carriage return
    int 0x10
    popa
    ret


