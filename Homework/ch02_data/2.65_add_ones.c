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

void show_int(int x) {
	printf(" show_int\n");
    show_bytes((byte_pointer) &x, sizeof(int));
}

int odd_ones(unsigned int x){
    x ^= x>>16;
    x ^= x>>8;
    x ^= x>>4;
    x ^= x>>2;
    x ^= x>>1;
    x &= 0x01;
    return x;
}

int main(void){
    printf("%d\n",odd_ones(0x00000000));
    printf("%d\n",odd_ones(0x01000101));

    return 0;
}