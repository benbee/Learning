#include <stdio.h>
//#include <conio.h>
#include <math.h>

void find_root(float a, float b, float c);

int main(int argc, char *argv[])
{
    double a, b, c;

	printf("enter coefficiants of x^2, x, and constand: ");
	scanf("%f%f%f", &a, &b, &c);

	find_root(a, b, c);
    return 0;
}

void find_root(float a, float b, float c)
{
	double d, root1, root2;
	d = ((b*b) - (4*a*c));

	if (d >= 0) {
		printf("roots are real\n");
		root1 = (-b + sqrt(d)) / (2 * a);
		root2 = (-b - sqrt(d)) / (2 * a);
		printf("root1 = %f\n", root1);
		printf("root2 = %f\n", root2);
	} else
	{
		printf("roots are imaginary\n");
		printf("root1 = %e + i%e", -b / (2 * a), sqrt(-d) / (2 * a));
		printf("root2 = %e - i%e", -b / (2 * a), sqrt(-d) / (2 * a));
	}
}
