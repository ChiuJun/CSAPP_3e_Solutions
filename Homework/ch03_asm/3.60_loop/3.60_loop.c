#include <assert.h>

extern long asm_loop(long x, int n);

long loop(long x,int n){
    long result=0;
    long mask;
    for(mask=1;mask!=0;mask<<=n){
        result |= x&mask;
    }
    
    return result;
}

int main(void){
    long x = 0x12345678;
    for(long i=0;i<10000;i++){
        assert(asm_loop(x+i, 2) == loop(x+i, 2));
    }
    
    return 0;
}