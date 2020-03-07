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

int any_odd_one(unsigned int x){
    show_unsigned_int(x);

    return !!(0xAAAAAAAA & x);
}

int main(void){
    printf("%d\n",any_odd_one(0x02));
    printf("%d\n",any_odd_one(0x04));

    return 0;
}