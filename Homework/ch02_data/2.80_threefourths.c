#include <stdio.h>
#include <limits.h>
#include <assert.h>

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

int threefourths(int x){
    int pos = !(x&INT_MIN);
    int tmp = x;
    (pos && (tmp = x+(1<<2)-1) );

    return x-(tmp>>2);
}

int main(void){
    int x = 0x80000004;
    printf(" x=%d\n fun:%d\n exp:%d\n",x,threefourths(x),(int) (x*(3.0/4.0)));
    assert( threefourths(x) == (int) (x*(3.0/4.0)) );

    for(x=-16;x<=16;x++){
        printf(" x=%d\n fun:%d\n exp:%d\n",x,threefourths(x),(int) (x*(3.0/4.0)));
        assert( threefourths(x) == (int) (x*(3.0/4.0)) );
    }

    return 0;
}