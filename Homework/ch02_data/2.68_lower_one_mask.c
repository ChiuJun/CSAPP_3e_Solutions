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

int lower_one_mask(int n){
    int x = 1;
    x = (x<<n-1<<1) - 1;
    return x;
}

int main(void){
    show_int(lower_one_mask(32));
    show_int(lower_one_mask(17));
    show_int(lower_one_mask(1));

    return 0;
}