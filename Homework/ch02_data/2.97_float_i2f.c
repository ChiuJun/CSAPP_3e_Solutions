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

//i>0
int bits_length(int i) {
    unsigned u = (unsigned)i;
    int length = 0;
    while (u >= (1<<length)) {
        length++;
    }

    return length;
}

unsigned int bits_mask(int L) {
    return (unsigned int) -1 >> (32-L);
}

float_bits float_i2f(int i) {
    unsigned sig, exp, frac, rest, exp_sig, round_part;
    unsigned bits, fbits;
    unsigned bias = 0x7F;

    if (i == 0) {
        sig = 0;
        exp = 0;
        frac = 0;
        return sig << 31 | exp << 23 | frac;
    }
    if (i == INT_MIN) {
        sig = 1;
        exp = bias + 31;
        frac = 0;
        return sig << 31 | exp << 23 | frac;
    }

    sig = !!(i&0x80000000);
    i = sig? -i:i;//!!!

    bits = bits_length(i);
    fbits = bits - 1;
    exp = bias + fbits;

    rest = i & bits_mask(fbits);
    if (fbits <= 23) {
        frac = rest << (23 - fbits);
        exp_sig = exp << 23 | frac;
    } else {
        int offset = fbits - 23;
        int round_mid = 1 << (offset - 1);

        round_part = rest & bits_mask(offset);
        frac = rest >> offset;
        exp_sig = exp << 23 | frac;

        // round to even
        if (round_part < round_mid) {
        // nothing
        } else if (round_part > round_mid) {
            exp_sig += 1;
        } else {
        // round_part == round_mid
            if ((frac & 0x1) == 1)
                exp_sig += 1;
        }
    }

    return sig << 31 | exp_sig;
}
    
int main(void) {
    int i;

    i = INT_MIN;
    assert(u2f(float_i2f((unsigned) i)) == (float)i);
    i = -1000;
    assert(u2f(float_i2f((unsigned) i)) == (float)i);
    i = 0;
    assert(u2f(float_i2f((unsigned) i)) == (float)i);
    i = 1000;
    assert(u2f(float_i2f((unsigned) i)) == (float)i);
    i = INT_MAX;
    assert(u2f(float_i2f((unsigned) i)) == (float)i);

    return 0;
}