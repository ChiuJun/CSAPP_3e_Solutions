#include <stdio.h>
#include <inttypes.h>

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

int signed_high_prod(int x, int y) {
  int64_t mul = (int64_t)x * (int64_t)y;
  
  return mul >> 32;
}

unsigned int unsigned_high_prod(unsigned int x,unsigned int y){
    int w = sizeof(int)<<3;
    int x_mask = (int)x>>(w - 1);
    int y_mask = (int)y>>(w - 1);

    return signed_high_prod((int)x,(int)y) + (unsigned)(x_mask&y) + (unsigned)(y_mask&x);
}

int main(void){
    unsigned x = 0x12345678;
    unsigned y = 0x9abcdef0;

    show_int(signed_high_prod((int)x,(int)y));
    show_unsigned_int(unsigned_high_prod(x,y));

    return 0;
}