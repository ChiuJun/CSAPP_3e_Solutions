#include <stdio.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = len; i > 0; i--)
	    printf(" %.2x", start[i-1]);
    printf("\n");
}

void show_int(int x) {
	printf(" show_int\n");
    show_bytes((byte_pointer) &x, sizeof(int));
}

int is_legal(int x){
    printf("x:%d\n",x);
    printf("!~x:%d\n",!~x);
    printf("!x:%d\n",!x);
    printf("!~(x|~0xFF):%d\n",!~(x|~0xFF));
    printf("!((x>>((sizeof(int)-1)<<3))&0xFF):%d\n",!((x>>((sizeof(int)-1)<<3))&0xFF));
    return (!~x) || (!x) || (!~(x|~0xFF)) || (!((x>>((sizeof(int)-1)<<3))&0xFF));
}

int main(void){
    int x;
    scanf("%d",&x);
    show_int(x);
    printf("%d\n",is_legal(x));

    return 0;
}