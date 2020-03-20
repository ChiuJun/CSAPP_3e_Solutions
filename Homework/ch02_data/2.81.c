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

//bug:while k==w
int fun_a(int k){
    //return ~((1<<k)-1);
    return -1<<k;
}

int fun_b(int k,int j){
    return ~fun_a(k) << j;
}

int main(void){
    int k=32,j=4;
    show_int(fun_a(k));
    show_int(fun_b(k,j));

    return 0;
}