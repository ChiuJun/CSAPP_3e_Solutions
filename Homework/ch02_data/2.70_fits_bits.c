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

int fits_bits(int x, int n){
    int w = sizeof(int)<<3;
    
    return x<<(w-n)>>(w-n) == x;
}

int main(void){
    printf("300:%d\n",fits_bits(300,8));
    printf("127:%d\n",fits_bits(127,8));
    printf("-128:%d\n",fits_bits(-128,8));

    return 0;
}