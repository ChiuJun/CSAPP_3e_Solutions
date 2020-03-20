#include <stdio.h>
#include <limits.h>

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

int tsub_ok(int x,int y){
    int sub = x-y;
    int sig_mask = INT_MIN;//0x80 00 00 00 

    int pos_over = !(x & sig_mask) &&  (y & sig_mask) &&  (sub & sig_mask);
    int neg_over =  (x & sig_mask) && !(y & sig_mask) && !(sub & sig_mask);

    return !(pos_over||neg_over);
}

int main(void){
    printf(" tsub_ok:%d\n INT_MAX - -1:\t%d\n",tsub_ok(INT_MAX,-1) ,INT_MAX- -1);
    show_int(INT_MAX- -1);
    printf(" tsub_ok:%d\n INT_MIN -  1:\t%d\n",tsub_ok(INT_MIN,1),INT_MIN-1);
    show_int(INT_MIN-1);
    printf(" tsub_ok:%d\n INT_MAX -  1:\t%d\n",tsub_ok(INT_MAX,1) ,INT_MAX-1);
    show_int(INT_MAX-1);
    printf(" tsub_ok:%d\n INT_MIN - -1:\t%d\n",tsub_ok(INT_MIN,-1),INT_MIN- -1);
    show_int(INT_MIN- -1);

    return 0;
}