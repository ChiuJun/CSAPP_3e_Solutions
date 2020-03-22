#include <stdio.h>
#include <assert.h>
#include <math.h>

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

float u2f(unsigned int x) {
    return *(float*) &x;
}

float fpwr2(int x) {
    /* Result exponent and fraction */
    unsigned int exp, frac;
    unsigned int u;
    int bias = 127;

    if (x < (1-bias + -23)) {
        /* Too small. Return 0.0 */
        exp = 0;
        frac = 0;
    } else if (x < 1-bias) {
        /* Denormalized result */
        exp = 0;
        frac = 1 <<  -(x-(1-bias));
    } else if (x < 254-bias + 1) {
        /* Normalized result */
        exp = x + bias;
        frac = 0;
    } else {
        /* Too big, Return +oo */
        exp = 0xFF;
        frac = 0;
    }

    u = exp << 23 | frac;

    return u2f(u);
}

int main(void) {
    assert(fpwr2(0) == powf(2,0));
    assert(fpwr2(100) == powf(2,100));
    assert(fpwr2(-100) == powf(2,-100));
    assert(fpwr2(1000) == powf(2,1000));
    assert(fpwr2(-1000) == powf(2,-1000));

    return 0;
}