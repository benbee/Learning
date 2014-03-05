#include <stdio.h>

int main(int argc, char *argv[])
{
    struct 
	{
		union {
			char a, b;
			int c;
		} d;
		int e[5];
	} f, *p = &f;

//	p->b = ' ';					/* wrong */
	p->e[3] = 10;
	(*p).d.a = '*';
//	p->d->c = 20;				/* wrong */
	
	return 0;
}
