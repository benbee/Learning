#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 1;
    float n;
    printf("Watch out! Here come a bunch of fractions!\n");

    while (i++ < 30){
	n = 1/(float)i;
	printf("%f\n", n);
    }
    printf("That's all folks!\n");
    
    return 0;			/* 呵呵，程序的结束，嘎嘎 */
}
