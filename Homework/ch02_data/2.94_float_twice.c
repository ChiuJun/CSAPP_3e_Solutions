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

unsigned int f2u(float f){
    return * (unsigned int*)&f;
}

float u2f(unsigned int x){
    return * (float*)&x;
}

float_bits float_twice(float_bits f){
    unsigned int sig = f>>31;
    unsigned int exp = f>>23 & 0xFF;
    unsigned int frac = f & 0x7FFFFF;

    if(exp==0xFF)
        return f;

    //ref DreamAndDead/CSAPP-3e-Solutions/chapter2/code/floats/float-twice.c
    if (exp == 0){
        frac <<= 1;
    }
    else if (exp == 0xFe){
        exp = 0xFF;
        frac = 0;
    }
    else{
        exp += 1;
    }

    return sig<<31 | exp<<23 | frac;
}

int main(void) {
    float f = INT_MAX;
    float inf = u2f(0x7f800000);
    assert(u2f(float_twice(f2u(f))) == f*2);
    f = 0;
    assert(u2f(float_twice(f2u(f))) == f*2);
    f = INT_MIN;
    assert(u2f(float_twice(f2u(f))) == f*2);
    f = 0.0/0.0;//NaN
    assert(float_twice(f2u(f)) == f2u(f));
    unsigned int x = 0x00065432;//exp == 0
    assert(u2f(float_twice(x)) == u2f(x)*2);
    x = 0x00765432;//exp == 0
    assert(u2f(float_twice(x)) == u2f(x)*2);
    x = 0x7F765432;//exp == 0xFe => u2f(x)*2 == inf
    assert(u2f(float_twice(x)) == inf);

    return 0;
}