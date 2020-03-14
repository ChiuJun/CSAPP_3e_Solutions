#include <stdio.h>

typedef unsigned char* byte_pointer;
typedef unsigned packed_t;

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

int xbyte(packed_t word, int bytenum){
    int leftshift = (sizeof(int)-1-bytenum)<<3;
    int rightshift = (sizeof(int)-1)<<3;

    //cast to int!!
    return (int)word<<leftshift>>rightshift;
}

int main(void){
    printf("%d\n",xbyte(0x00FF1108,0));
    printf("%d\n",xbyte(0x00FF1108,1));
    printf("%d\n",xbyte(0x00FF1108,2));
    printf("%d\n",xbyte(0x00FF1108,3));

    return 0;
}