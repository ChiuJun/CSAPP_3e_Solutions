#include <assert.h>

typedef enum {NEG, ZERO, POS, OTHER} range_t;

range_t find_range(float x) {
    __asm__(
        "vxorps %xmm1,%xmm1,%xmm1\n\t"
        "vucomiss     %xmm1,%xmm0\n\t"
        "movq $1, %rax\n\t"
        "movq $0, %r8\n\t"
        "movq $2, %r9\n\t"
        "movq $3, %r10\n\t"
        "cmovbq %r8,%rax\n\t"
        "cmovaq %r9,%rax\n\t"
        "cmovpq %r10,%rax\n\t"
        ".retResult:\n\t"
    );
}

int main(void){
    assert(find_range(-10.0)==0);
    assert(find_range(0.0)==1);
    assert(find_range(10.0)==2);    

    return 0;
}