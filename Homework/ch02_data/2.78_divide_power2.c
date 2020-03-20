#include <stdio.h>
#include <limits.h>

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

int divide_power2(int x,int k){
    int neg = x & INT_MIN;
    (neg && (x = x+(1<<k)-1) );

    return x >> k;
}

int main(void){
    int x = 0x8000000F;
    int k = 2;
    show_int(divide_power2(x,k));
    printf("%d %d\n",divide_power2(x,k),x/(1<<k));

    return 0;
}