CC = clang
LD = toolchain/binutils/bin/i686-elf-ld -no-PIE
CFLAGS = --target=i386-pc-elf -std=c99 -c -I inc -I libc/inc -fno-PIC
AC = nasm
AFLAGS = -felf32
LFLAGS = -T linker.ld

BIN = build/kernel.bin

ASMSOURCES = $(wildcard src/kernel/*.asm)
CSOURCES = $(wildcard src/kernel/*.c)
CSOURCES += $(wildcard src/*.c)
CSOURCES += $(wildcard src/kernel/drivers/*.c)

COBJECTS = $(CSOURCES:src/%.c=obj/%.o)
ASMOBJECTS = $(ASMSOURCES:src/%.asm=obj/%.o)

$(BIN): $(COBJECTS) $(ASMOBJECTS)
	@mkdir -p build
	@echo "[LINK] $(BIN)"
	@$(LD) $(LFLAGS) $(COBJECTS) $(ASMOBJECTS) -o $(BIN)

obj/%.o: src/%.c
	@echo "[COMPILE-C] $<"
	@mkdir -p obj/kernel/drivers
	@$(CC) $(CFLAGS) $< -o $@

obj/%.o: src/%.asm
	@echo "[COMPILE-ASM] $<"
	@mkdir -p obj/kernel/drivers
	@$(AC) $(AFLAGS) $< -o $@

clean:
	@rm -rf build
	@rm -rf obj

run-qemu:
	@echo "Running in QEMU"
	@qemu-system-i386 -kernel $(BIN)
