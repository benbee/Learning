/* cm to inches */
int main(int argc, char *argv[])
{
    float body_height;
    float cm_per_inch = 2.54;
    printf("Please enter your height in cm: \n");
    scanf("%f", &body_height);
    printf("You are %.2f inches tall.\n", body_height / cm_per_inch);
    return 0;
}
