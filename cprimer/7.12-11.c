#include <stdio.h>

#define K_VER_PRICE 1.25
#define BETA_VULGARIS_PRICE 0.65
#define CARROT_PRICE 0.89
#define DISCOUNT 0.05
#define DISCOUNT_LINE 100

float cal_trans(float weight);
float cal_cost(float k_weight, float b_weight, float c_weight);
char choose_goods(void);
float get_goods_weight(void);
void print_order(float k_weight, float b_weight, float c_weight, float total_cost);
void print_stars(void);
int get_anything_else(void);

int main(int argc, char *argv[])
{
    float k_weight;
    float b_weight;
    float c_weight;
    char choice;
    int continue_buy = 0;
    float total_cose = 0;

    k_weight = b_weight = c_weight = 0;

    printf("Please select the kinds of goods you like:\n");
    choice = choose_goods();
    while (choice != 'q') {
	switch(choice)
	{
	case 'a':
	case 'A':
	    k_weight += get_goods_weight();
	    break;
	case 'b':
	case 'B':
	    b_weight += get_goods_weight();
	    break;
	case 'c':
	case 'C':
	    c_weight += get_goods_weight();
	    break;
	default:
	    break;
	}
	continue_buy = get_anything_else();
	if (continue_buy) {
	    choice = choose_goods();
	} else {
	    choice = 'q';
	}
    }

    print_order(k_weight, b_weight, c_weight, cal_cost(k_weight, b_weight, c_weight));
    printf("BYE!\n");
    
    return 0;
}

void print_stars(void)
{
    int i;
    for (i = 0; i <= 16; i++) {
	printf("***");
    }
    printf("\n");
}

char choose_goods(void)
{
    char choice;
    
    print_stars();
    printf("Select goods:\n");
    printf("a) k_whatever\tb) beta vulgaris\n");
    printf("c) carrot\tq) quit\n");
    print_stars();

    while ((choice =getchar()) != EOF) {
	switch(choice)
	{
	case 'a':
	case 'A':
	    return 'a';
	case 'b':
	case 'B':
	    return 'b';
	case 'c':
	case 'C':
	    return 'c';
	case 'q':
	case 'Q':
	    return 'q';
	case '\n':
	    break;
	default:
	    printf("WARNING: Wrong choice, please choice again.\n");
	    break;
	}
    }
}

float get_goods_weight(void)
{
    float goods_weight;
    /*if (ch == 'a') {
	goods_name = 'K';
    } else if (ch == 'b') {
	goods_name = 'B';
    } else if (ch == 'c') {
	goods_name = 'C';
    } else {
	printf("wrong vir type!\n");
    }*/

    printf("How many pounds do you want?\n");
    scanf("%f", &goods_weight);
    return goods_weight;
}

float cal_trans(float weight)
{
    if (weight <= 5) {
	return 3.50;
    } else if (weight > 5 && weight < 20) {
	return 10;
    } else {
	return 8 + 0.1 * weight;
    }
}

float cal_cost(float k_weight, float b_weight, float c_weight)
{
    float goods_cost;
    float total_weight;
    
    total_weight = k_weight + b_weight + c_weight;
    goods_cost = k_weight * K_VER_PRICE + b_weight * BETA_VULGARIS_PRICE + c_weight * CARROT_PRICE;

    if (goods_cost >= DISCOUNT_LINE)
	goods_cost *= (1 - DISCOUNT);
    return goods_cost + cal_trans(total_weight);
}

void print_order(float k_weight, float b_weight, float c_weight, float total_cost)
{
    print_stars();
    printf("Here is your bill:\n\n");
    printf("%.2f pounds K_whatever\n", k_weight);
    printf("%.2f pounds beta vulgaris\n", b_weight);
    printf("%.2f pounds carrot\n", c_weight);
    printf("\t\t\t\tTotal cost: %.2f\n", total_cost);
    print_stars();
}

int get_anything_else(void)
{
    char ch;
    
    printf("Do you want anything else?(y or n): ");
    while ((ch = getchar()) != EOF) {
	switch(ch)
	{
	case 'Y':
	case 'y':
	    return 1;
	case 'N':
	case 'n':
	    return 0;
	case '\n':
	    break;
	default:
	    printf("Please enter \"y\" or \"n\"!\n");
	    break;
	}

    }
	
}
