#include <stdio.h>

typedef unsigned char* byte_pointer;

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

unsigned int sr1(unsigned int x,int k){
    //perform shift arithmetically
    unsigned int xsra = (int)x>>k;

    int w = sizeof(unsigned int)<<3;
    //bug:while k==0,mask==0
    //bug has been solved x<<s means x<<(s%w)
    //unsigned int mask = (0x01<<(w-k))-1;
   
    //from DreamAndDead/CSAPP-3e-Solutions
    int mask = (int)-1 << (w-k-1) << 1;

    return xsra & ~mask;
}

int sra(int x,int k){
    //perform shift logically
    int xsrl = (unsigned int)x>>k;

    //bug:while k==0 h==0x8000,mask==0
    //bug has been solved
    int w = sizeof(unsigned int)<<3;
    int h = (0x01<<(w-1))&x;
    int mask = (int) -1 << (w-k-1) << 1;
    //!h-1 ==> 0x8000==>0xFFFF or 0x0000==>0x0000
    mask = mask &(!h - 1);

    return xsrl | mask;
}

int main(void){
    unsigned int x = 0xFF000000;
    show_unsigned_int(sr1(x,4));
    show_int(sra((int)x,8));
    return 0;
}