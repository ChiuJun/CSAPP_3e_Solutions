#include <stdio.h>
#include <limits.h>
#include <assert.h>

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

void show_float(float x) {
	printf(" show_float\n");
    show_bytes((byte_pointer) &x, sizeof(float));
}

unsigned int f2u(float f){
    return * (unsigned int*)&f;
}

float u2f(unsigned int x){
    return * (float*)&x;
}

int float_f2i(float_bits f){
    unsigned int sig = f>>31;
    unsigned int exp = f>>23 & 0xFF;
    unsigned int frac = f & 0x7FFFFF;
    unsigned int bias = 127;

    int x;

    if (exp < 0x7f){
        x = 0;
    }else if(exp >= 31+bias){
        x = 0x80000000;
    }else{
        unsigned int E = exp - bias;
        unsigned int M = frac | 0x800000;
        if (E > 23) {
            x = M << (E - 23);
        } else {
            x = M >> (23 - E);
        }
    }

    return sig ? -x : x;
}

int main(void) {
    float f;

    f = INT_MIN;
    assert(float_f2i(f2u(f)) == (int)f);
    f *= 2;
    assert(float_f2i(f2u(f)) == (int)f);
    f = 0;
    assert(float_f2i(f2u(f)) == (int)f);
    f = INT_MAX;
    assert(float_f2i(f2u(f)) == (int)f);
    f *= 2;
    assert(float_f2i(f2u(f)) == (int)f);
    f = u2f(0x7f800000);//inf
    assert(float_f2i(f2u(f)) == (int)f);
    f = 0.0/0.0;//NaN
    assert(float_f2i(f2u(f)) == 0x80000000);
    f = 0.12345678;
    assert(float_f2i(f2u(f)) == (int)f);

    return 0;
}