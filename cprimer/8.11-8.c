#include <stdio.h>

char choose_operator(void);
double enter_first_num(void);
double enter_second_num(void);
double cal_result(double first, char op, double second);
char alpha_to_math(char operator);

int main(int argc, char *argv[])
{
    char operator;
    double first_num;
    double second_num;
    first_num = second_num = 0;

    while ((operator = choose_operator()) != 'q') {
	first_num = enter_first_num();
	printf("First number is %.2lf\n", first_num);
	second_num = enter_second_num();
	printf("Second number is %.2lf\n", second_num);
	printf("%.2lf %c %.2lf = %.2lf\n", first_num, alpha_to_math(operator), second_num, cal_result(first_num, alpha_to_math(operator), second_num));
	printf("\n");
    }

    printf("Bye!\n");
    return 0;
}

char choose_operator(void)
{
    char ch;
    
    printf("Enter the operation of youor choice:\n");
    printf("a. add\t\ts. subtract\n");
    printf("m. multiply\td. divide\n");
    printf("q. quit\n");
    while((ch = getchar()) != EOF) {
	switch(ch)
	{
	    case 'a':
		return 'a';
	    case 's':
		return 's';
	    case 'm':
		return 'm';
	    case 'd':
		return 'd';
	    case 'q':
		return 'q';
	    case '\n':
		break;
	    default:
		printf("Please enter the right choice, such a, d or q\n");
	}
    }
    while (getchar() !='\n')
	continue;
}

double enter_first_num(void)
{
    double n;

    printf("Enter first number: ");
    while (scanf("%lf", & n) != 1) {
	printf("Please enter a number, such as 2.5, -1, -1.78E8 or 3: ");
    }

    return n;
}

double enter_second_num(void)
{
    double n;

    printf("Enter second number: ");
    while (scanf("%lf", & n) != 1) {
	printf("Please enter a number, such as 2.5, -1, -1.78E8 or 3: ");
    }

    return n;
}

double cal_result(double first, char op, double second)
{
    switch(op)
    {
	case '+':
	    return first + second;
	case '-':
	    return first - second;
	case '*':
	    return first * second;
	case '/':
	    return first / second;
	default:
	    printf("error cal input!\n");
	    break;
    }
}

char alpha_to_math(char operator)
{
    switch(operator)
    {
	case 'a':
	    return '+';
	case 's':
	    return '-';
	case 'd':
	    return '/';
	case 'm':
	    return '*';
    }
}
