#include <stdio.h>

int main(int argc, char *argv[])
{
    double daphe_invest, deirdre_invest;
    int i;

    daphe_invest = 100;
    deirdre_invest = 100;
    i = 0;
    while (daphe_invest >= deirdre_invest) {
	daphe_invest += 100 * 0.1;
	deirdre_invest += deirdre_invest * 0.05;
	i++;
    }

    printf("Need %d years.\n", i);
    
    return 0;
}
