IMAGE:
	dd if=bc of=IMAGE bs=512 count=1 conv=notrunc
bs.o:
	as86 -o bs.o bs.s
bc.o:
	bcc -c -ansi bc.c -o bc.o
bc:
	ld86 -d -o bc bs.o bc.o /usr/lib/bcc/libc.a

qemu:
	qemu -nographic -fda IMAGE -no-fd-bootchk

clean:
	rm bs.o bc.o bc IMAGE

