C_SRCS			= src/kernel/entry_point/entry.c \
				src/kernel/utils/print.c

C_OBJS			= $(C_SRCS:.c=.o)
C_FLAGS			= -ffreestanding -c -std=c99 -Isrc/kernel/ 

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

kernel: $(C_OBJS) $(ASM_OBJ) 
	i386-elf-ld -o $(KERNEL_BIN) $(LD_FLAGS) $(ASM_OBJ) $(C_OBJS) 

image: $(BOOT_SECT_NAME) kernel
	cat $(BOOT_SECT_NAME) $(KERNEL_BIN) > $(IMAGE_NAME)

run: image
	qemu-system-x86_64 $(QEMU_FLAGS) $(IMAGE_NAME)

clean:
	$(RM) $(C_OBJS) $(ASM_OBJ) $(KERNEL_BIN) $(BOOT_SECT_NAME)

fclean: clean
	$(RM) $(IMAGE_NAME)

re: fclean all

%.o: %.c
	i386-elf-gcc $(C_FLAGS) $< -o $@

%.o: %.asm
	nasm $(ASM_FLAGS) $< -o $@

%.bin: %.asm
	nasm -f bin $< -o $@