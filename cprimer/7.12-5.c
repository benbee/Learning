#include <stdio.h>

float cal_average(int sum, int num);

int main(int argc, char *argv[])
{
    int even_cnt;		/* even number like 2 */
    int odd_cnt;		/* odd  number like 3 */
    int even_sum;
    int odd_sum;
    int num;
    even_sum = even_cnt = odd_cnt = odd_sum = 0;
    
    printf("Please enter sum numbers for analysis: \n");
    scanf("%d", &num);
    while (num != 0) {
	switch(num % 2 == 0 && num != 1) {
	case 1:
	    even_sum += num;
	    even_cnt++;
	    break;
	case 0:
	    odd_sum += num;
	    odd_cnt++;
	    break;
	default:
	    break;
	}
	scanf("%d", &num);
    }

    printf("There %s %d %s, average is %.2f.\n", even_cnt>=2?"are":"is", even_cnt, even_cnt>=2?"evens":"even", cal_average(even_sum, even_cnt));
    printf("And there %s %d %s, average is %.2f.\n", odd_cnt>=2?"are":"is", odd_cnt, odd_cnt>=2?"odds":"odd", cal_average(odd_sum, odd_cnt));
    
    return 0;
}

float cal_average(int sum, int num)
{
    return (float)sum / (float)num;
}
