#include <stdio.h>

int main(int argc, char *argv[])
{
    char ch;
    int space_cnt;
    int line_cnt;
    int oc_cnt;

    space_cnt = line_cnt = oc_cnt = 0;

    printf("Please enter something to analysis\n");
    while ((ch = getchar()) != '#') {
	if (ch == '\n') {
	    line_cnt++;
	} else if (ch == ' ') {
	    space_cnt++;
	} else {
	    oc_cnt++;
	}
    }

    printf("space  line  other_character\n");
    printf("%5d %5d %5d\n", space_cnt, line_cnt, oc_cnt);
    
    return 0;
}
