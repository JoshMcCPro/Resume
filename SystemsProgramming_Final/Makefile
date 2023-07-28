ASM = nasm
LNK = ld
ASFLAGS = -f elf
LDFLAGS = -m elf_i386
OBJS = copy.o

copy: $(OBJS)
	$(LNK) $(LDFLAGS) $(OBJS) -o $@

copy.o: copy.asm functions.asm
	$(ASM) $(ASFLAGS) copy.asm

clean:
	rm -f *.o copy
