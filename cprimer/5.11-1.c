#include <stdio.h>

#define M_PER_H 60

int main(int argc, char *argv[])
{
    int time;

    printf("Enter time in minutes:\n");
    scanf("%d", &time);
    while (time > 0) {
	printf("It's %d hour and %d minute\n", time/M_PER_H, time%M_PER_H);
	scanf("%d", &time);
    }
    return 0;
}
