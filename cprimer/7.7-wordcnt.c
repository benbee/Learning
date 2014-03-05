/* count charactor wors and lines */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define STOP '|'

int main(int argc, char *argv[])
{
    char c;
    char prev;
    long n_chars = 0L;
    int n_lines = 0;
    int n_words = 0;
    int p_lines = 0;
    bool inword = false;

    printf("Please enter text to be analyzed(| to terminate): \n");
    prev = '\n';		/* identify full line */
    while ((c = getchar()) != STOP) {
	n_chars++;
	if (c == '\n')
	    n_lines++;
	if (!isspace(c) && !inword) {
	    inword = true;
	    nwords++;
	}
	if (isspace(c) && inword) {
	    inword = false;
	}
	prev = c;
    }

    if (prev != '\n')
	plines = 1;
    printf("characters = %ld, words = %d, lines = %d, ", n_chars, n_words, n-lines);
    printf("partial lines = %d\n", p_lines);
    
    return 0;
}

















