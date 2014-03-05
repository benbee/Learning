#include <stdio.h>
struct x {
    int a, b;
};

int main(int argc, char *argv[])
{
    struct x x_val;
	x_val.a = 2;
	printf("%d",(&x_val)->a);
    return 0;
}
