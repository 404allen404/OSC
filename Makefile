# Compiler and flags
CC      = aarch64-none-linux-gnu-gcc
LD      = aarch64-none-linux-gnu-ld
OBJCOPY = aarch64-none-linux-gnu-objcopy
OBJDUMP = aarch64-none-linux-gnu-objdump
QEMU    = qemu-system-aarch64
GDB     = aarch64-none-linux-gnu-gdb

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

# Source files
SRC = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Kernel binary
KERNEL = kernel8.img

# Linker script
LINKER_SCRIPT = linker.ld

# Include flags
INC_FLAGS = -I$(INC_DIR)

# Default target
all: $(KERNEL)

# Rule to create object files from source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(INC_FLAGS) -nostartfiles -c $< -o $@

# Rule to link object files into kernel binary
$(KERNEL): $(OBJ)
	$(LD) -T $(LINKER_SCRIPT) -o kernel8.elf $(OBJ)
	$(OBJCOPY) -O binary kernel8.elf $@

# Rule to display assembly using objdump
objdump:
	$(OBJDUMP) -D kernel8.elf

# Rule to run QEMU
qemu:
	$(QEMU) -M raspi3b -kernel kernel8.img -display none -serial null -serial stdio -S -s 

# Rule to debug with GDB
gdb:
	$(GDB)

clean:
	rm -f $(OBJ) kernel8.elf $(KERNEL)
