/* use rhodium to value your weight */
#include <stdio.h>

int main(int argc, char *argv[])
{
    float weight;
    float value;
    printf("Are you worth you weight in rhdium?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weight in pounds: ");
    /* get input from user */
    scanf ("%f", &weight);
    /** asume rhodium worth $770 per angsi**/
    // 14.5833
    value = 770 * weight * 14.5833;
    printf("Your weight in rhdium is worth $%.2f.\n", value);
    printf("You are easily worth that! If rhodium proces drop, \n");
    printf("eat more to maintain you value.\n");
    return 0;
}
