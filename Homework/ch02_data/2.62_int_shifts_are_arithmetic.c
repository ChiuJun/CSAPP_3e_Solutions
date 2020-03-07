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

int int_shifts_are_arithmetic(void){
    //DreamAndDead/CSAPP-3e-Solutions
    //int num = -1;
    //return !(num ^ (num >> 1));
    int x = 0x01;
    x = x<<((sizeof(int)<<3)-1);
    x = x>>((sizeof(int)<<3)-1);
    show_int(x);
    return (x&0x2)>>1;
}

int main(void){
    printf("%d\n",int_shifts_are_arithmetic());

    return 0;
}