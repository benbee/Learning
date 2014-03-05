#include <stdio.h>

#define SINGLE_BASE 17850
#define MASTER_BASE 23900
#define MARRIED_BASE 297500
#define MARRIED_DIVORCED_BASE 147875
#define B_RATE 0.15
#define S_RATE 0.28

float cal_tax(int choice, float income);
int choose_status(void);
void print_stars();

int main(int argc, char *argv[])
{
    int choice;
    float income;

    printf("Please choose your status:\n");
    choice = choose_status();
    printf("Please enter your income before tax:\n");
    scanf("%f", &income);
    printf("You should pay %.2f  tax.\n", cal_tax(choice, income));
    return 0;
}

void print_stars(void)
{
    int i;
    for (i = 0; i < 16; ++i) {
	printf("***");
    }
    printf("\n");
}

int choose_status(void)
{
    char choice;
    
    print_stars();
    printf("1) SINGLE\t2) MASTER\n");
    printf("3) MARRIED\t4) MARRIED AND DEVOICED\n");
    printf("5) quit\n");
    print_stars();

    while((choice = getchar()) != EOF) {
	switch(choice)
	{
	case '1':
	    return 1;
	case '2':
	    return 2;
	case '3':
	    return 3;
	case '4':
	    return 4;
	case '5':
	    exit(0);
	case '\n':
	    break;
	default:
	    printf("Please enter 1-5.\n");
	    break;
	}
    }
}

float cal_tax(int choice, float income)
{
    if (choice == 1 && income <= SINGLE_BASE) {
	return income * B_RATE;
    } else if (choice == 1 && income > SINGLE_BASE) {
	return SINGLE_BASE * B_RATE + (income - SINGLE_BASE) * S_RATE;
    } else if (choice == 2 && income <= MASTER_BASE) {
	return income * B_RATE;
    } else if (choice == 2 && income > MASTER_BASE) {
	return MASTER_BASE * B_RATE + (income - MASTER_BASE) * S_RATE;
    } else if (choice ==  3 && income <= MARRIED_BASE) {
	return income * B_RATE;
    } else if (choice == 3 && income > MARRIED_BASE) {
	return MARRIED_BASE * B_RATE + (income - MARRIED_BASE) * S_RATE;
    } else if (choice == 4 && income <= MARRIED_DIVORCED_BASE) {
	return income * B_RATE;
    } else if (choice ==4 && income > MARRIED_DIVORCED_BASE){
	return MARRIED_DIVORCED_BASE * B_RATE + (income - MARRIED_DIVORCED_BASE) * S_RATE;
    }
}
