#include <stdio.h>

//#define BASE_SALARY 10.0
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25
#define BASE1 300
#define BASE2 450



float cal_salary(float work_time, float base_salary);
float choose_base_salary(void);
void print_star(void);

int main(int argc, char *argv[])
{
    float work_time;
    float salary;
    float base_salary;
    int choice;

    base_salary = choose_base_salary();
    
    printf("Please enter your total work time:\n");
    scanf("%f", &work_time);

    if (work_time > 40) {
	work_time = 40 + (work_time - 40) * 1.5;
    }

    salary = cal_salary(work_time, base_salary);
    printf("You got $%.2f salary.\n", salary);
    
    return 0;
}

float cal_salary(float work_time, float base_salary)
{
    float result;
    float salary;

    salary = base_salary * work_time;
    if (salary <= BASE1) {
	result = salary - salary * RATE1;
    } else if (salary >BASE1 && salary <= BASE2) {
	result = BASE1 * (1 - RATE1) + (salary - BASE1) * (1 - RATE2);
    } else {
	result = BASE1 * (1 - RATE1) + (BASE2 - BASE1) * (1 - RATE2) + (salary - BASE2) * (1 - RATE3);
    }
    return result;
}

float choose_base_salary(void)
{
    char ch;
    print_star();
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr\t2) $9.33/hr\n");
    printf("3) $10.00/hr\t4) $11.20/hr\n");
    printf("5) quit\n");
    print_star();

    while ((ch = getchar()) != EOF) {
	switch(ch)
	{
	    case '1':
		return 8.75;
		//break;
	    case '2':
		return 9.33;
		//break;
	    case '3':
		return 10.00;
		//break;
	    case '4':
		return 11.20;
		//break;
	    case '5':
		exit(0);
		//break;
	    default:
		printf("WRONG choice, please enter 1-5.\n");
		break;
	}
    }
}

void print_star(void)
{
    int i = 0;
    for (i = 0; i < 16; ++i) {
	printf("****");
    }
    printf("\n");
}
