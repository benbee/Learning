/* using switch */

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char ch;
    printf("Give me a leeter of the alphabet, and I will give \n");
    printf("an animal name\nbegeinning with that ltter.\n");
    printf("Please type in a letter: type # to end my act.\n");
    while ((ch = getchar()) != '#') {
	if ('\n' == ch)
	    continue;
	if (islower(ch)) {	/* only recon lower character */
	    switch (ch) {
		case 'a':
		    printf("arigli, a wild sheep of Asia\n");
		    break;
	        case 'b':
		    printf("babirysa, a wild pig of Malay\n");
		    break;
		case 'c':
		    printf("coati, racoonlike mammal\n");
		    break;
		case 'd':
		    printf("desman, aquatic, molelike critter\n");
		    break;
	        case 'e':
		    printf("echidna, the spiny anteater\n");
		    break;
 	        case 'f':
		    printf("fisher, brownish marten\n");
		    break;
		default:
		    printf("That's a stymper.\n");
	    }
	} else {
	    printf("I recognize only lowercase letters.\n");
	}
	while (getchar() != '\n') {
	    continue;
	}
	printf("Please type another letter or a #.\n");
    }
    printf("Bye!\n");
    return 0;
}
