#include <stdio.h>
#include <limits.h>
#include <assert.h>

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

//broken when x is INT_MIN
int fun_a(int x,int y){
    printf(" fun_a:-x ");
    show_int(-x);
    return (x<y) == (-x>-y);
}

//?
int fun_b(int x, int y) {
    return ((x + y) << 4) + y - x == 17 * y + 15 * x;
}

// right
// ~x + ~y + 1
//    =>
// ~x + 1 + ~y + 1 - 1
//    =>
// -x + -y - 1
//    =>
// -(x + y) - 1
//    =>
// ~(x + y) + 1 - 1
//    =>
// ~(x + y)
int fun_c(int x, int y) {
  return ~x + ~y + 1 == ~(x + y);
}

// right
// -(ux-uy)
//     =>
// -( (x(w-1)-y(w-1))2^w + (x-y) )
//     =>
// (y(w-1)-x(w-1))2^w + (y-x)
//     =>
// (unsigned) (y-x)
int fun_d(int x, int y) {
  unsigned ux = (unsigned) x;
  unsigned uy = (unsigned) y;

  return (ux-uy) == -(unsigned) (y-x);
}

// right
// x >> 2 << 2
//   =>
// x & 0xFFFFFFFC
//   =>
// ((x >> 2) << 2) <= x
int fun_e(int x, int y) {
  return ((x >> 2) << 2) <= x;
}

int main(void){
    int x,y;
    x = INT_MIN,y = 1;
    printf(" fun_a(%d,%d):%d\n",x,y,fun_a(x,y));
    x = INT_MIN,y = -1;
    printf(" fun_b(%d,%d):%d\n",x,y,fun_b(x,y));
    printf(" fun_c(%d,%d):%d\n",x,y,fun_c(x,y));
    printf(" fun_d(%d,%d):%d\n",x,y,fun_d(x,y));
    printf(" fun_e(%d,%d):%d\n",x,y,fun_e(x,y));

    return 0;
}