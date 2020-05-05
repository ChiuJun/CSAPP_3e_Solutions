all:
	gcc -c -m64 asm_loop.s -o asm_loop.o
	gcc asm_loop.o 3.60_loop.c -o test

test:
	./test

clean:
	rm asm_loop.o
