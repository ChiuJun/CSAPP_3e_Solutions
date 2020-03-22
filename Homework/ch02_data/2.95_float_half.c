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

float_bits float_half(float_bits f){
    unsigned int sig = f>>31;
    unsigned int exp = f>>23 & 0xFF;
    unsigned int frac = f & 0x7FFFFF;

    if(exp==0xFF)
        return f;
    // ref DreamAndDead/CSAPP-3e-Solutions/chapter2/code/floats/float-half.c
    // IEEE 754,round to even
    int addition = (frac&0x3)==0x3;

    if (exp == 0){
        frac >>= 1;
        frac += addition;
    }else if(exp == 1){
        unsigned int temp = f&0x7FFFFFFF;
        temp >>= 1;
        temp += addition;
        exp = temp>>23 & 0xFF;
        frac = temp & 0x7FFFFF;
    }else{
        exp -= 1;
    }

    return sig<<31 | exp<<23 | frac;
}

int main(void) {
    float f = INT_MAX;
    float inf = u2f(0x7f800000);
    assert(u2f(float_half(f2u(f))) == f/2);
    f = 0;
    assert(u2f(float_half(f2u(f))) == f/2);
    f = INT_MIN;
    assert(u2f(float_half(f2u(f))) == f/2);
    f = 0.0/0.0;//NaN
    assert(float_half(f2u(f)) == f2u(f));
    unsigned int x = 0x0006543f;
    assert(u2f(float_half(x)) == u2f(x)/2);
    x = 0x00865432;
    assert(u2f(float_half(x)) == u2f(x)/2);

    return 0;
}