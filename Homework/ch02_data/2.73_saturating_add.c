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

int saturating_add(int x,int y){
    int sum = x+y;
    int sig_mask = INT_MIN;//1<<((sizeof(int)<<3)-1)

    int pos_over = !(x & sig_mask) && !(y & sig_mask) &&  (sum & sig_mask);
    int neg_over =  (x & sig_mask) &&  (y & sig_mask) && !(sum & sig_mask);

    (pos_over&&(sum=INT_MAX) || neg_over&&(sum=INT_MIN));

    return sum;
}

int main(void){
    printf(" saturating_add:%d\n INT_MAX+1:\t%d\n",saturating_add(INT_MAX,1) ,INT_MAX+1);
    show_int(saturating_add(INT_MAX,1));
    show_int(INT_MAX+1);
    printf(" saturating_add:%d\n INT_MIN-1:\t%d\n",saturating_add(INT_MIN,-1),INT_MIN-1);
    show_int(saturating_add(INT_MIN,-1));
    show_int(INT_MIN-1);

    return 0;
}