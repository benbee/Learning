#include <stdio.h>

int main(int argc, char *argv[])
{
    struct test_struct {
		double real;
		double imaginary;
	};

	struct test_struct c1, c2, c3;

	c1.real = 0.0;
	c1.imaginary = 1.0;

	c2.real = 1.0;
	c2.imaginary = 0.0;

	/* c1.real = c2.real; */
	/* c1.imaginary = c2.imaginary; */

	c1 = c2;
	
	c3.real = c1.real + c2.real;
	c3.imaginary = c1.imaginary + c2.imaginary;

	printf("The value of c3: \n");
	printf("real: %.2f\n", c3.real);
	printf("imaginary: %.2f\n", c3.imaginary);
	
	return 0;
}
