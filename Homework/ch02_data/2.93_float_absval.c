#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <math.h>

typedef unsigned char* byte_pointer;
typedef unsigned packed_t;

typedef unsigned float_bits;

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

unsigned int f2u(float f){
    return * (unsigned int*)&f;
}

float u2f(unsigned int x){
    return * (float*)&x;
}

float_bits float_absval(float_bits f){
    unsigned int exp = f>>23 & 0xFF;
    unsigned int frac = f & 0x7FFFFF;

    if(exp==0xFF && frac!=0)
        return f;
        
    return f & 0x7fffffff;
}

int main(void) {
    float f = INT_MAX;
    assert(u2f(float_absval(f2u(f))) == fabsf(f));
    f = 0;
    assert(u2f(float_absval(f2u(f))) == fabsf(f));
    f = INT_MIN;
    assert(u2f(float_absval(f2u(f))) == fabsf(f));
    f = 0.0/0.0;
    assert(float_absval(f2u(f)) == f2u(f));

    return 0;
}