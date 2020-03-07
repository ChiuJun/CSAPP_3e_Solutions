#include <stdio.h>

typedef unsigned char* byte_pointer;

int is_little_endian(void){
	int x = 1;
	byte_pointer byte_start = (byte_pointer) &x;
	return *byte_start;
}

int main(void){
	printf("is_little_endian:%d\n",is_little_endian());
	return 0;
}
