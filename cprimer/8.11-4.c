#include <stdio.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    int in_word;
    char ch;
    int word_count;
    int char_count;

    in_word = 0;
    word_count = 0;
    char_count = 0;

    while ((ch = getchar()) != EOF) {
	if (isalpha(ch)) {
	    if (in_word == 0) {
		in_word = 1;
		word_count++;
	    }
	    char_count++;
	} else {
	    if (in_word == 1) {
		in_word = 0;
	    }
	}
    }
    
    printf("The average character of each word is %.2f\n", (float)char_count / word_count);

    return 0;
}
