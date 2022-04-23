section .text
    extern isr_handler

isr_global_handler:
    pusha                 ; push all registers
    mov ax, ds
    push eax              ; save ds
    
    mov ax, 0x10          ; load kernel data segment
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    call isr_handler

    pop ebx             ; restore kernel data segment
    mov ds, bx
    mov es, bx
    mov fs, bx
    mov gs, bx

    popa                ; restore all registers
    add esp, 0x8        ; restore stack for erro no been pushed

    sti                 ; re-enable interrupts
    iret


%macro ISR 1
  global isr%1
  isr%1:
    cli
    push byte 0
    push byte %1
    jmp isr_global_handler
%endmacro

ISR 0
ISR 1
ISR 2
ISR 3
ISR 4
ISR 5
ISR 6
ISR 7
ISR 8
ISR 9
ISR 10
ISR 11
ISR 12
ISR 13
ISR 14
ISR 15
ISR 16
ISR 17
ISR 18
ISR 19
ISR 20
ISR 21
ISR 22
ISR 23
ISR 24
ISR 25
ISR 26
ISR 27
ISR 28
ISR 29
ISR 30
ISR 31
ISR 128
