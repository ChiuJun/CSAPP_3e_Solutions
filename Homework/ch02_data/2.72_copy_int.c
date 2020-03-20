#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void copy_int(int val,void *buf,int maxbytes){
    if(maxbytes >= (int) sizeof(val))
        memcpy(buf,(void *) &val,sizeof(val));
}

int main(void){
    int maxbytes = sizeof(int);
    void* buf = malloc(maxbytes);
    int val;

    val = 0x12345678;
    copy_int(val, buf, maxbytes);
    show_bytes(buf,maxbytes);

    val = 0xAABBCCDD;
    copy_int(val, buf, 0);
    show_bytes(buf,maxbytes);

    free(buf);

    return 0;
}