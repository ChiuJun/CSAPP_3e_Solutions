#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

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

void *calloc(size_t nmemb, size_t size){
    if(nmemb==0 || size==0)
        return NULL;
    
    size_t bufsize = nmemb * size;
    void *mem = NULL;
    if(bufsize/size == nmemb){
        mem = malloc(bufsize);
        if(mem != NULL)
            memset(mem,0,bufsize);
    }

    return mem;
}

int main(void){
    void * ptr;
    ptr = calloc(INT_MAX,INT_MAX);
    printf("%p\n",ptr); 
    free(ptr);

    ptr = calloc(2,sizeof(int));
    printf("ptr:%p\n%d %d\n",ptr,*(int*)ptr,*((int*)ptr+1)); 
    free(ptr);

    return 0;
}