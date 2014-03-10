#include <stdio.h>
#include <stdlib.h>

#define NUM 5

int my_compare(const void *elem1, const void *elem2)
{
	unsigned int *p1, *p2;
	p1 = (unsigned int *)elem1;
	p2 = (unsigned int *)elem2;
	return (*p1 % 10) - (*p2 % 10);
}

int main(int argc, char *argv[])
{
    unsigned int an[NUM] = {8, 123, 11, 104};
	qsort(an, NUM, sizeof(unsigned int), my_compare);
	for (int i = 0; i < NUM; i++) {
		printf("\t%d", an[i]);
	}
    return 0;
}
