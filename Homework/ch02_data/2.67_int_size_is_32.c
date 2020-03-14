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

int int_size_is_32(){
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;
    show_int(set_msb);
    show_int(beyond_msb);
    return set_msb && !beyond_msb;
}

int main(void){
    printf("%d\n",int_size_is_32());

    return 0;
}