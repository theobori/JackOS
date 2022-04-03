BOOT_SECTOR_SRC		= src/boot/boot_sector.asm
BOOT_SECTOR_OBJ		= $(BOOT_SECTOR_SRC:.asm=.o)
BOOT_SECTOR_FLAGS	= -f bin

IMAGE_NAME			= JackOS-image.bin
RUN_FLAGS			= -fda

all: boot_sector

run: re
	qemu-system-x86_64 $(RUN_FLAGS) $(BOOT_SECTOR_OBJ)

boot_sector: $(BOOT_SECTOR_OBJ)

clean:
	$(RM) $(BOOT_SECTOR_OBJ)

fclean: clean
	$(RM) $(IMAGE_NAME)

re: fclean all

%.o: %.asm
	nasm $< $(BOOT_SECTOR_FLAGS) -o $@