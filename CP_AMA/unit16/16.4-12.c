#include <stdio.h>

union s_test {
    double a;
	union {
		char b[4];
		double c;
		int d;
	} e;
	char f[4];
};

int main(int argc, char *argv[])
{
    union s_test *p = malloc(sizeof(union s_test)); /* 8 bytes ? */
	//free(p);
    return 0;
}
