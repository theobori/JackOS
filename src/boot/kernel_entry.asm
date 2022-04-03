[bits 32]
[extern kernel_entry]   ; Define calling point. Must have same name as kernel.c 'main' function
call kernel_entry       ; Calls the C function. The linker will know where it is placed in memory
jmp $
