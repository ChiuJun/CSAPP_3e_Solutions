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

int rotate_left(unsigned int x, int n){
    int w = sizeof(int)<<3;
    x = x << n | x >> (w-n-1) >> 1;
    return x;
}

int main(void){
    show_int(rotate_left(0x12345678,0));
    show_int(rotate_left(0x12345678,4));
    show_int(rotate_left(0x12345678,31));

    return 0;
}