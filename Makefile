CC				= i386-elf-gcc
NASM			= nasm
LD				= i386-elf-ld
QEMU 			= qemu-system-x86_64
GRUB			= /usr/bin/grub-mkrescue

C_FLAGS 		= -W -Wall -Wextra -ffreestanding -std=c99 -Isrc
LD_FLAGS 		= -T config/linker.ld -nostdlib -m elf_i386
ASM_FLAGS 		= -f elf32
QEMU_FLAGS		=

UTILS_PATH		= src/utils
SHELL_PATH		= src/shell
DRIVERS_PATH	= src/drivers
DANIEL_PATH		= src/GUI
TTY_PATH		= $(DANIEL_PATH)/tools/tty
SYS_PATH		= src/systems
C_SRC			= src/kernel.c \
				src/gdt.c \
				$(DANIEL_PATH)/lib/init.c \
				$(DANIEL_PATH)/lib/put_pixel.c \
				$(DANIEL_PATH)/lib/draw_square.c \
				$(DANIEL_PATH)/lib/draw_char.c \
				$(TTY_PATH)/init.c \
				$(TTY_PATH)/update.c \
				$(TTY_PATH)/display.c \
				$(TTY_PATH)/buffer.c \
				$(TTY_PATH)/commands.c \
				$(TTY_PATH)/clear.c \
				$(TTY_PATH)/builtin_commands/ping.c \
				$(TTY_PATH)/builtin_commands/pwd.c \
				$(TTY_PATH)/builtin_commands/ls.c \
				$(TTY_PATH)/builtin_commands/mkdir.c \
				$(TTY_PATH)/builtin_commands/cd.c \
				$(TTY_PATH)/builtin_commands/echo.c \
				$(TTY_PATH)/builtin_commands/cat.c \
				$(TTY_PATH)/builtin_commands/clear.c \
				src/bios/protected/bios32.c \
				$(UTILS_PATH)/memory/malloc.c \
				$(UTILS_PATH)/memory/memcpy.c \
				$(UTILS_PATH)/memory/memset.c \
				$(UTILS_PATH)/string/in.c \
				$(UTILS_PATH)/string/itoa.c \
				$(UTILS_PATH)/string/split.c \
				$(UTILS_PATH)/string/strcmp.c \
				$(UTILS_PATH)/string/strcpy.c \
				$(UTILS_PATH)/string/strlen.c \
				$(UTILS_PATH)/string/join.c \
				$(UTILS_PATH)/string/count.c \
				$(UTILS_PATH)/string/strncpy.c \
				$(UTILS_PATH)/string/strrev.c \
				$(UTILS_PATH)/string/upper.c \
				$(UTILS_PATH)/string/trim.c \
				$(UTILS_PATH)/string/strdup.c \
				$(UTILS_PATH)/string/strndup.c \
				$(UTILS_PATH)/string/atoi.c \
				$(UTILS_PATH)/string/strcat.c \
				src/interrupts/isr.c \
				src/interrupts/idt.c \
				$(DRIVERS_PATH)/conn/ports.c \
				$(DRIVERS_PATH)/conn/timer.c \
				$(DRIVERS_PATH)/screen/screen.c \
				$(DRIVERS_PATH)/keyboard/keyboard.c \
				$(DRIVERS_PATH)/mouse/mouse.c \
				$(SHELL_PATH)/clear.c \
				$(SHELL_PATH)/exec.c \
				$(SHELL_PATH)/shell.c \
				$(SHELL_PATH)/builtin_commands/help.c \
				$(SHELL_PATH)/builtin_commands/setxkbmap.c \
				$(SHELL_PATH)/builtin_commands/clear.c \
				$(SYS_PATH)/files/init.c \
				$(SYS_PATH)/files/create.c \
				$(SYS_PATH)/files/list.c \
				$(SYS_PATH)/files/write.c \
				$(SYS_PATH)/files/read.c \
				$(SYS_PATH)/files/change_dir.c \
				$(SYS_PATH)/files/dir_exist.c \
				$(SYS_PATH)/files/get_folder.c \

ASM_PATH		= src/asm
ASM_SRC			= $(ASM_PATH)/entry.asm \
				$(ASM_PATH)/load_gdt.asm \
				$(ASM_PATH)/load_idt.asm \
				$(ASM_PATH)/irq.asm \
				$(ASM_PATH)/isr.asm \
				$(ASM_PATH)/bios32_call.asm \
				src/GUI/fonts/daniel.asm

OBJ 			= $(C_SRC:.c=.o) $(ASM_SRC:.asm=.o)
TARGET_BIN		= boot/JackOS.bin
TARGET_ISO		= $(TARGET_BIN:.bin=.iso)

all: build

build: $(OBJ)
	$(LD) $(LD_FLAGS) -o $(TARGET_BIN) $(OBJ)
	$(GRUB) -o $(TARGET_ISO) .

run: re
	$(QEMU) $(QEMU_FLAGS) $(TARGET_ISO)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET_BIN)
	$(RM) $(TARGET_ISO)

re: fclean all

%.o: %.c
	$(CC) -c $(C_FLAGS) -o $@ $<

%.o: %.asm
	$(NASM) $(ASM_FLAGS) -o $@ $<

