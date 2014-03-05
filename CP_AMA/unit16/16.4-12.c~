#include <stdio.h>

struct s_test {
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
    struct s_test *p = malloc(sizeof(struct s_test)); /* 24 bytes */
	free(p);
    return 0;
}
