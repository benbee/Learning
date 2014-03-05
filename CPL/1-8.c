#include <stdio.h>

main()
{
    int c, ns, nt, nl;
    ns = nt = nl = 0;

    while ((c = getchar()) != EOF){
	if (c == ' '){
	    ++ns;
	}
	if (c == '\t'){
	    ++nt;
	}
	if (c == '\n'){
	    ++nl;
	}
    }
    printf("%4d,%4d,%4d\n", ns, nt, nl);
}
