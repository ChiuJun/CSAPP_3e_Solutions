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

int mul3div4(int x){
    //no overflow
    //return x-divide_power2(x,2);

    return divide_power2((x<<1)+x,2);
}

int main(void){
    int x = 0x80000004;
    printf("%d\n%d\n",mul3div4(x),(x*3/4));
    return 0;
}