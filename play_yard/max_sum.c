//
//  max_sum.c
//
//
//  Created by zhangbo on 5/19/14.
//
//

#include <stdio.h>
//#include <omp.h>


#define MAX_NUM 10

int max_sum(const int *a)
{
    int b[MAX_NUM];
    int i;
    int max;

    for (i = 0; i < MAX_NUM; i++) {
        printf("a[i]: %d\n", a[i]);

        if (i == 0)
            b[i] = a[i];
        else  if (b[i-1] + a[i] > a[i]) {
            b[i] = b[i-1] + a[i];
            printf("b[i]: %d\n", b[i]);
        } else {
            b[i] = a[i];
            printf("b[i]: %d\n", b[i]);

        }
    }

    max = -1000;
    for (i = 0; i < MAX_NUM; i++) {
        if (max < b[i]) {
            max = b[i];
        }
    }

    return max;
}


int main(int argc, char *argv[])
{
    int a[] = { 1, 2, -3, 4, -9, -20, -50, 78, 90, -100 };

    printf("MAX: %d\n", max_sum(a));

    return 0;
}
