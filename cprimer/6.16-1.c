#include <stdio.h>

#define AB 26

int main(int argc, char *argv[])
{
    int i;
    char ab[AB];

    for (i = 0; i < AB; i++) {
	ab[i] = 'a' + i;
    }

    for (i = 0; i < AB; ++i) {
	printf("%3c", ab[i]);
    }
    
    return 0;
}
