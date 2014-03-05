/* calculate how many molecule in  water by quarts */

int main(int argc, char *argv[])
{
    double water_molecule_weight = 3.0e-23;
    int water_weight_per_quart = 950;
    int quarts;

    printf("Please enter the value in quart: \n");
    scanf("%d", &quarts);
    printf("So so, there are %e melocules in the water. Wow, that's a huge number\n", (quarts * water_weight_per_quart) / water_molecule_weight);
    return 0;
}










