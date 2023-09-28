IMAGE:bc 
	dd if=bc of=IMAGE bs=512 count=1 conv=notrunc
bc:bs.o bc.o
	ld86 -d -o bc bs.o bc.o /usr/lib/bcc/libc.a	
bs.o:bs.o
	as86 -o bs.o bs.s
bc.o:bc.c
	bcc -c -ansi bc.c -o bc.o



qemu:
	qemu -nographic -fda IMAGE -no-fd-bootchk

.PHONY:clean IMAGE

clean:
	rm bs.o bc.o bc IMAGE

