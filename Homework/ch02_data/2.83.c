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

// Y = B2U(y) //y has k bits.
// x = 0.yyyyyy...
//
// x<<k == y.yyyyyy...
//     =>
// x == x<<k - Y
//     =>
// Y == x<<k - x
//     =>
// Y == x * (2^k - 1)
//     =>
// x == Y/(2^k - 1)   
//     =>
// x == B2U(y)/(2^k - 1)
void calc_x(unsigned int Y,int k){
    printf("x = %d/%d\n",Y,(1<<k)-1);
}

int main(void){
    calc_x(0b101,3);
    calc_x(0b0110,4);
    calc_x(0b010011,6);

    return 0;
}