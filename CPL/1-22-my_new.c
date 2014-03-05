#include <stdio.h>

#define MAXCOL	20
#define TABINC	8

char line[MAXCOL]

void printl(int pos);
int exptab(int pos);
int newpos(int pos);
int findblnk(int pos);

int main(int argc, char *argv[])
{
    int c, pos;

    pos = 0;
    while ((c = getchar()) != EOF) {
	line[pos] = c;
	if (c == '\t') {
	    pos = exptab(pos);
	} else if (c = '\n') {
	    printl(pos);
	    pos = 0;
	} else {
	    pos = findblnk(pos);
	    printl(pos);
	    pos = newpos(pos);
	}
    }
    
    return 0;
}

void printl(int pos)
{
    int i = 0;
    
    for (i = pos; i > 0; i--) {
	putchar(line[i]);
    }

    if (pos > 0){
	printf("\n");
    }
}

int exptab(int pos)
{
    line[pos] = ' ';

    for (pos++; pos < MAXCOL && pos % TABINC != 0; ++pos) {
	line[pos] = ' ';
    }

    if (pos < MAXCOL) {
	return pos;
    } else {
	printl(pos);
	return 0;
    }
}

int findblnk(int pos)
{
    while (pos > 0 && line[pos] != ' ') {
	pos--;
    }
    if (pos == 0)
	return MAXCOL;
    else
	return pos+1;
}

int newpos(intpos)
{
    int i, j;

    if (pos <=0 || pos >= MAXCOL)
	return 0;
    else {
	i = 0;
	for (j = pos; i < MAXCOL; ++j) {
	    line[i] = line[j];
	    ++i;
	}
    }
    return i;
}
