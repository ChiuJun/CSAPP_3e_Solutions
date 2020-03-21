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

int float_le(float x, float y) {
    unsigned int ux = *(unsigned int*) &x;
    unsigned int uy = *(unsigned int*) &y;

    unsigned int sx = ux >> 31;
    unsigned int sy = uy >> 31;

    return (!(ux<<1) && !(uy<<1)) || (sx && !sy) ||
        (!sx && !sy && ux <= uy) || (sx && sy && ux >= uy); 
}

int main(void) {
    printf("%d\n",float_le(-0, +0));
    printf("%d\n",float_le(-8, 8));
    printf("%d\n",float_le(-16, -8));
    printf("%d\n",float_le(8, 16));

    return 0;
}