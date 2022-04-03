[org 0x7c00]                ; offset because BIOS put boot_sector at adress 0x7c00 so all of the registers and adresses will have an offset

mov bx, WELCOME_MESSAGE     ; Printing Welcome Message
call print
call print_newline

; call load_kernel
jmp $                       ; jmp to current adress making infinite loop

%include "src/boot/utils/print.asm"

WELCOME_MESSAGE:
    db "Welcome into JackOS !", 0

times 510 - ($-$$) db 0     ; fill adress with 0 unti mem length == 510
dw 0xaa55                   ; two last bytes for magic number
                            ; magic number is read by the BIOS looking for if it's an os or not
                            ; so the total mem length == 512 (sector size)