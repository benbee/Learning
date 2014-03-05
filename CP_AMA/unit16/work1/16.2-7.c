/**
 * a simple fraction calculate system
 * author: bembee
 * email: habwtl@foxmail.com
 */

#include <stdio.h>

struct fraction {
	int numerator;
	int denominator;
};

int get_gcd(int a, int  b);
int get_lcm(int a, int b);
int double_max(int a, int b);
int double_min(int a, int b);
struct fraction simp_frac(struct fraction frac);
struct fraction common_deno(struct fraction a, int lcm);
struct fraction add_fraction(struct fraction a, struct fraction b);
struct fraction sub_fraction(struct fraction a, struct fraction b);
struct fraction multi_fraction(struct fraction a, struct fraction b);
struct fraction divi_fraction(struct fraction a, struct fraction b);
struct fraction get_frac(void);
void print_frac(struct fraction frac);
void print_result(struct fraction a, struct fraction b, char ch);

int main(int argc, char *argv[])
{
	struct fraction a = get_frac();
	struct fraction b = get_frac();

	print_result(a, b, '+');
	print_result(a, b, '-');
	print_result(a, b, '*');
	print_result(a, b, '/');
}

int double_max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int double_min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int get_gcd(int a, int b)
{
	int max = double_max(a, b);
	int min = double_min(a, b);

	if (max % min != 0)
		return get_gcd(min, (max % min));
	return min;
}

int get_lcm(int a, int b)
{
	int result = (a * b) / get_gcd(a, b);

	if (result > 0)
		return result;
	else
		return -result;
}

struct fraction simp_frac(struct fraction frac)
{
	struct fraction retval;
	int gcd = get_gcd(frac.numerator, frac.denominator);

	if (gcd == 1)
		return frac;
	else {
		retval.numerator = frac.numerator / gcd;
		retval.denominator = frac.denominator / gcd;

		return retval;
	}
}

struct fraction common_deno(struct fraction a, int lcm)
{
	struct fraction retval;

	retval.numerator = 	a.numerator * (lcm / a.denominator);
	retval.denominator = lcm;

	return retval;
}

struct fraction add_fraction(struct fraction a, struct fraction b)
{
	struct fraction retval;
	int lcm = get_lcm(a.denominator, b.denominator);

	a = common_deno(a, lcm);
	b = common_deno(b, lcm);

	retval.numerator = a.numerator + b.numerator;
	retval.denominator = lcm;

	return simp_frac(retval);
}

struct fraction sub_fraction(struct fraction a, struct fraction b)
{
	struct fraction retval;
	int lcm = get_lcm(a.denominator, b.denominator);
		
	a = common_deno(a, lcm);
	b = common_deno(b, lcm);

	retval.numerator = a.numerator - b.numerator;

	return simp_frac(retval);
}

struct fraction multi_fraction(struct fraction a, struct fraction b)
{
	struct fraction retval;

	retval.numerator =  a.numerator * b.numerator;
	retval.denominator = a.denominator * b.denominator;

	return simp_frac(retval);
}
struct fraction divi_fraction(struct fraction a, struct fraction b)
{
	struct fraction retval;
	
	retval.numerator = a.numerator * b.denominator;
	retval.denominator = a.denominator * b.numerator;

	return simp_frac(retval);
}

struct fraction get_frac(void)
{
	struct fraction retval;

	printf("Enter the denominator of the fraction: ");
	scanf("%d", &retval.denominator);
	while (retval.denominator == 0) {
		printf("denominator can not equal zero!\n");
		printf("Enter the denominator of the fraction: ");
		scanf("%d", &retval.denominator);
	}
	
	printf("Enter the numerator of the fraction: ");
	scanf("%d", &retval.numerator);

	return retval;
}

void print_frac(struct fraction frac)
{
	if (frac.denominator == 1)
		printf("%d", frac.numerator);
	else
		printf("%d/%d", frac.numerator, frac.denominator);
}

void print_result(struct fraction a,
				  struct fraction b, char ch)
{


	switch (ch) {
	case '+':
		print_frac(a);
		printf(" + ");
		print_frac(b);
		printf(" = ");
		print_frac(add_fraction(a, b));
		printf("\n");
		break;
	case '-':
		print_frac(a);
		printf(" - ");
		print_frac(b);
		printf(" = ");
		print_frac(sub_fraction(a, b));
		printf("\n");
		break;
	case '*':
		print_frac(a);
		printf(" * ");
		print_frac(b);
		printf(" = ");
		print_frac(multi_fraction(a, b));
		printf("\n");
		break;
	case '/':
		print_frac(a);
		printf(" / ");
		print_frac(b);
		printf(" = ");
		print_frac(divi_fraction(a, b));
		printf("\n");
		break;
	default:
		printf("'\nwrong argv\n");
	}
}
