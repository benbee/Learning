#include <stdio.h>

int main(int argc, char *argv[])
{
    float lucky_money = 100;
    int i;

    while (lucky_money >0) {
	lucky_money = lucky_money + lucky_money * 0.08 - 10;
	i++;
    }

    printf("Need %d years to empty his count.\n", i);
    
    return 0;
}
