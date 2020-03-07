#include <stdio.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = len; i > 0; i--)
	    printf(" %.2x", start[i-1]);
    printf("\n");
}

void show_unsigned_int(unsigned int x) {
	printf(" show_unsigned_int\n");
    show_bytes((byte_pointer) &x, sizeof(unsigned int));
}

unsigned int replace_byte(unsigned int x,int i,unsigned char b){
    unsigned int mask = 0xFF;
    mask = mask<<(i*8);
    x = (x & ~mask)|(b<<(i*8));
    return x;
}

int main(void){
    unsigned int x = 0x12345678;
    unsigned char b = 0xAB;
    show_unsigned_int(x);
    show_unsigned_int(replace_byte(x,2,b));
    show_unsigned_int(replace_byte(x,0,b));

    return 0;
}