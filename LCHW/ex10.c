#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    printf("argc is: %d\n", argc);

    // go through each string in argv
    // why am I skipping argv[0]

    for (i = 0; i < argc; i++) {
	printf("argc %d: %s\n", i, argv[i]);
    }

    // let's make our own array of strings
    char *states[] = {
	"California", "Oregon",
	"Washingtion", "Texas"
    };
    int num_states = 4;

    for (i = 0; i < num_states; i++) {
	printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}