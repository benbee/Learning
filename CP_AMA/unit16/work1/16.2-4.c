#include <stdio.h>

typedef struct {
	double real;
	double imaginary;
} Complex;

Complex make_complex(double real, double imaginary);
Complex add_complex(Complex a, Complex b);

int main(int argc, char *argv[])
{

	Complex c1, c2, c3;

	c1 = make_complex(0.0, 1.0);
	c2 = make_complex(2.0, 0.0);
	
	/* c1.real = 0.0; */
	/* c1.imaginary = 1.0; */

	/* c2.real = 1.0; */
	/* c2.imaginary = 0.0; */

	/* c1.real = c2.real; */
	/* c1.imaginary = c2.imaginary; */

	c1 = c2;

	c3 = add_complex(c1, c2);
	/* c3.real = c1.real + c2.real; */
	/* c3.imaginary = c1.imaginary + c2.imaginary; */

	printf("The value of c3: \n");
	printf("real: %.2f\n", c3.real);
	printf("imaginary: %.2f\n", c3.imaginary);
	
	return 0;
}

Complex make_complex(double real, double imaginary)
{
	Complex result;

	result.real = real;
	result.imaginary = imaginary;

	return result;
}

Complex add_complex(Complex a, Complex b)
{
	Complex c;

	c.real = a.real + b.real;
	c.imaginary = a.imaginary + b.imaginary;

	return c;
}
