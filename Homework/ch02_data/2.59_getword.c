#include <stdio.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = len; i > 0; i--)
	    printf(" %.2x", start[i-1]);
    printf("\n");
}

void show_int(int x) {
	printf(" show_int\n");
    show_bytes((byte_pointer) &x, sizeof(int));
}

int getword(int x,int y){
    int z = y;
    byte_pointer px = (byte_pointer) &x;
    byte_pointer pz = (byte_pointer) &z;
    *pz = *px;
    return z;
}

int main(void){
    int x = 0x89ABCDEF,y = 0x76543210;
    show_int(x);
    show_int(y);
    show_int(getword(x,y));

    return 0;
}