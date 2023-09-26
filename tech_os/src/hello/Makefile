all:
	qemu-system-i386 -nographic -fda bin/boot.bin
boot.bin:
	nasm boot.asm -f bin -o bin/boot.bin
