#include <assert.h>

typedef enum {NEG, ZERO, POS, OTHER} range_t;

range_t find_range(float x) {
    __asm__(
        "vxorps %xmm1,%xmm1,%xmm1\n\t"
        "vucomiss     %xmm1,%xmm0\n\t"
        "movl $0,%eax\n\t"
        "jb .retResult\n\t"
        "movl $1,%eax\n\t"
        "je .retResult\n\t"
        "movl $2,%eax\n\t"
        "ja .retResult\n\t"
        "movl $3,%eax\n\t"
        "jp .retResult\n\t"
        ".retResult:\n\t"
    );
}

int main(void){
    assert(find_range(-10.0)==0);
    assert(find_range(0.0)==1);
    assert(find_range(10.0)==2);    

    return 0;
}