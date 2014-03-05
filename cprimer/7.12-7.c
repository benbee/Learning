#include <stdio.h>

#define BASE_SALARY 10.0
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25
#define BASE1 300
#define BASE2 450



float cal_salary(float work_time);

int main(int argc, char *argv[])
{
    float work_time;
    float salary;
    
    printf("Please enter your total work time:\n");
    scanf("%f", &work_time);

    if (work_time > 40) {
	work_time = 40 + (work_time - 40) * 1.5;
    }

    salary = cal_salary(work_time);
    printf("You got $%.2f salary.\n", salary);
    
    return 0;
}

float cal_salary(float work_time)
{
    float result;
    float salary;

    salary = BASE_SALARY * work_time;
    if (salary <= BASE1) {
	result = salary - salary * RATE1;
    } else if (salary >BASE1 && salary <= BASE2) {
	result = BASE1 * (1 - RATE1) + (salary - BASE1) * (1 - RATE2);
    } else {
	result = BASE1 * (1 - RATE1) + (BASE2 - BASE1) * (1 - RATE2) + (salary - BASE2) * (1 - RATE3);
    }
    return result;
}


















