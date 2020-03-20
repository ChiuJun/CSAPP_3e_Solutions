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

int main(void){
    int x = 5;
    printf("A.%d %d\n",x*17,(x<<4)+x);
    printf("B.%d %d\n",x*-7,(-x<<3)+x);
    printf("C.%d %d\n",x*60,(x<<6)-(x<<2));
    printf("D.%d %d\n",x*-112,(x<<4)-(x<<7));

    return 0;
}