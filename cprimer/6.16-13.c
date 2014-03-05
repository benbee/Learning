#include <stdio.h>

#define AR_LENGTH 8

int main(int argc, char *argv[])
{
    int i;
    float a[8];
    float b[8];

    for (i = 0; i < 8; ++i) {
	a[i] = 0.0;
	b[i] = 0.0;
    }

    printf("Enter %d double numbers: \n", AR_LENGTH);
    for (i = 0; i < 8; ++i) {
        scanf("%f", &a[i]);
        if (i == 0)
            b[i] = a[i];
        else {
            b[i] = b[i-1] + a[i];
        }
    }


    for (i = 0; i < 8; ++i) {
        printf("%4.2lf\t", a[i]);
        printf("%4.2lf\n", b[i]);
    }
    return 0;
}
