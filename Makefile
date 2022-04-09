KPATH			= src/kernel
C_SRCS			= $(KPATH)/entry_point/entry.c \
				$(KPATH)/utils/string/itoa.c \
				$(KPATH)/utils/string/strlen.c \
				$(KPATH)/utils/string/strrev.c \
				$(KPATH)/utils/memory/malloc.c \
				$(KPATH)/drivers/interrupts/idt.c \
				$(KPATH)/drivers/interrupts/isr.c \
				$(KPATH)/drivers/ports.c \
				$(KPATH)/drivers/interrupts/timer.c \
				$(KPATH)/drivers/keyboard.c \
				$(KPATH)/shell/shell.c \
				$(KPATH)/shell/clear.c \
				$(KPATH)/shell/exec.c \
				$(KPATH)/drivers/screen/screen.c

C_OBJS			= $(C_SRCS:.c=.o)
C_FLAGS			= -W -Wall -Wextra -ffreestanding -c -std=c99 -Isrc/kernel/ 

ASM_SRC			= src/boot/kernel_entry.asm
ASM_OBJ			= $(ASM_SRC:.asm=.o)
ASM_FLAGS		= -f elf

KERNEL_BIN		= kernel.bin
LD_FLAGS		= -Ttext 0x1000 --oformat binary

BOOT_SECT_SRC	= src/boot/boot_sector.asm
BOOT_SECT_NAME	= $(BOOT_SECT_SRC:.asm=.bin)

QEMU_FLAGS		= -fda
IMAGE_NAME		= os-image.bin

all: image

kernel: $(C_OBJS) $(ASM_OBJ) $(KPATH)/drivers/interrupts/interrupts.o
	i386-elf-ld -o $(KERNEL_BIN) $(LD_FLAGS) $(ASM_OBJ) $(C_OBJS) $(KPATH)/drivers/interrupts/interrupts.o

image: $(BOOT_SECT_NAME) kernel
	cat $(BOOT_SECT_NAME) $(KERNEL_BIN) > $(IMAGE_NAME)

run: image
	qemu-system-x86_64 $(QEMU_FLAGS) $(IMAGE_NAME)

clean:
	$(RM) $(C_OBJS) $(ASM_OBJ) $(KERNEL_BIN) $(BOOT_SECT_NAME)
	$(RM) $(KPATH)/drivers/interrupts/interrupts.o

fclean: clean
	$(RM) $(IMAGE_NAME)

re: fclean all

%.o: %.c
	i386-elf-gcc $(C_FLAGS) $< -o $@

%.o: %.asm
	nasm $(ASM_FLAGS) $< -o $@

%.bin: %.asm
	nasm -f bin $< -o $@