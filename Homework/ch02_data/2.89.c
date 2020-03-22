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

// right
int fun_a(int x) {
    double dx = (double) x;

    return (float)x == (float)dx;
}

// wrong when x-y overflow 
int fun_b(int x,int y) {
    double dx = (double) x;
    double dy = (double) y;

    return dx-dy == (double)(x-y);
}

// right
int fun_c(int x,int y,int z) {
    double dx = (double) x;
    double dy = (double) y;
    double dz = (double) z;

    return (dx+dy)+dz == dx+(dy+dz);
}

// wrong
// double can store integer value at most 2^53 precisely
// it's possible that the value is over 2^53
// when (long)x*y > 2^53 && (long)x*y << 53 != 0 &&
//      (long)y*z > 2^53 && (long)y*z << 53 != 0 
// like 0x7fff ffff,0x7ffc fcfe,0x7efe feee
int fun_d(int x,int y,int z) {
    double dx = (double) x;
    double dy = (double) y;
    double dz = (double) z;

    return (dx*dy)*dz == dx*(dy*dz);
}

// wrong when x+z!=0 && x*z==0
int fun_e(int x,int z) {
    double dx = (double) x;
    double dz = (double) z;
    
    return dx/dx == dz/dz;
}

int main(void) {
    printf("fun_a:%d\n",fun_a(INT_MIN)&&fun_a(0)&&fun_a(INT_MAX));
    printf("fun_b:%d\n",fun_b(INT_MIN,1));
    printf("fun_c:%d\n",fun_c(1,INT_MAX,INT_MIN+1));
    printf("fun_d:%d\n",fun_d(INT_MAX,0x7ffcfcfe,0x7efefeee));
    printf("fun_e:%d\n",fun_e(0,1));

    return 0;
}