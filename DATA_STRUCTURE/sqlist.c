#include <stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;		/* make int as elemtype */
typedef int Status;

typedef struct  {
    ElemType data[MAXSIZE];
    int length;
} SqList;			/* define the sqlist structure */

Status visit(ElemType c)
{
    printf("%4d", c);
    return OK;
}

Status InitList(SqList *L) {	/* initialize sqlist */
    L->length = 0;

    return OK;
}

Status ListEmpty(SqList L) {	/* check the sqlist if empty */
    if(L.length == 0)
	return TRUE;
    else
	return FALSE;
}

Status ClearList(SqList *L) {	/* reset the sqlit to empty */
    L->length = 0;
    return OK;
}

int ListLength(SqList L) {	/* get the length of a sqlist */
    return L.length;
}

Status GetElem(SqList L, int i, ElemType *e) /* get the i position element */
{
    if (L.length == 0 || i < 1 || i > L.length)
	return ERROR;		/* when L  empty or i's position not right return error */
    *e = L.data[i-1];
    return OK;
}

Status ListInsert(SqList *L, int i, ElemType e) /* insert element e to position i */
{
    int k;

    if (L->length == MAXSIZE) {
	return ERROR;		/* can not insert anything when sqlist is full */
    }
    if (i < 1 || i > L->length + 1) {
	return ERROR;		/* position wrong */
    }
    if (i <= L->length) {	/* make position for element */
	for (k = L->length - 1; k >= i-1; k--) {
	    L->data[k+1] = L->data[k];
	}
    }
    L->data[i-1] = e;		/* insert element */
    L->length++;		/* increase sqlist length */

    return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e)
{
    int k;

    if (L->length == 0)
	return ERROR;		/* empty list can not delete anything */
    if (i < 1 || i > L->length)
	return ERROR;		/* wrong position to delete */
    *e = L->data[i-1];
    if (i < L->length) {	/* not the last one to delete */
	for (k = i; k < L->length; k++)
	    L->data[k - 1] = L->data[k];
    }

    L->length--;
    //printf("after ListDelete the lenth of L is %d\n", L->length);
    return OK;
}

Status ListTraverse(SqList L)	/* visit each element of sqlist */
{
    int i;

    for (i = 0; i < L.length; ++i) {
	visit(L.data[i]);
    }
    printf("\n");

    return OK;
}

int LocateElem(SqList L, ElemType e) /* get the locate of e */
{
    int i;

    if (L.length == 0)
	return 0;
    for (i = 0; i < L.length; ++i) {
	if (L.data[i] == e)
	    break;
    }

    if (i >= L.length)
	return 0;

    return i+1;
}

void unionL(SqList *La, SqList Lb) /* union Lb to La */
{				
    int La_len, Lb_len, i;
    ElemType e;
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb);

    for (i = 1; i <= Lb_len; ++i) {
	GetElem(Lb, i, &e);
	if (!LocateElem(*La, e))
	    ListInsert(La, ++La_len, e);
    }
    
}

void print_top_stars(int i)
{
    while (i > 0) {
	printf("*");
	i--;
    }
    printf("\n");
}

void print_bot_stars(int i)
{
    print_top_stars(i);
    printf("\n");
    printf("\n");
}


int main(int argc, char *argv[])
{
    int i,j;
    ElemType e;
    SqList L;
    SqList La, Lb;
    InitList(&L);
    InitList(&La);
    InitList(&Lb);

    /* now let's test each function */
    /* make a sqlist */
    print_top_stars(32);
    printf("Now let's enter some thing to the sqlist.\n");
    printf("How many elements do you want to input? \n");
    scanf("%d", &i);
    printf("Please enter %d values(user Enter to commit).\n", i);
    for (j = 0; j < i; ++j) {
	scanf("%d", &e);
	ListInsert(&L, j+1, e);
	if (j != i-1)
	    printf("Please enter next value:\n");
    }
    printf("Here is your sqlist:\n");
    ListTraverse(L);
    print_bot_stars(32);

    /* demo insert function */
    print_top_stars(32);
    printf("Please choose a position to insert: ");
    scanf("%d", &i);
    while (i < 1 || i > L.length) {
	printf("Warning: wrong position\n");
	scanf("%d", &i);
    };
    printf("Enter the instert value: ");
    scanf("%d", &e);
    ListInsert(&L, i, e);
    printf("Now the length of L is %d.\n", L.length);
    printf("The content of sqlist are: \n");
    ListTraverse(L);
    print_bot_stars(32);

    /* demo delete function */
    print_top_stars(32);
    printf("Please choose a position to delete: \n");
    scanf("%d", &i);
    while (i < 1 || i > L.length) {
	printf("Warning: wrong position\n");
	scanf("%d", &i);
    }
    ListDelete(&L, i, &e);
    printf("Now the length of L is %d.\n", L.length);
    printf("The content of sqlist are: \n");
    ListTraverse(L);
    print_bot_stars(32);

    /* demo locate function */
    print_top_stars(32);
    printf("This check if the value you enter in the sqlist,\n");
    printf("if in the sqlist return the position.\n");
    printf("Enter the value: \n");
    scanf("%d", &e);
    if (LocateElem(L, e) != 0) {
	printf("The position of %d is %d.\n", e, LocateElem(L, e));
    } else {
	printf("The value you enter is not in the sqlist.\n");
    }
    print_bot_stars(32);

    /* demo union sqlist */
    print_top_stars(32);
    printf("This test will union two sqlist, ");
    printf("now let's make another list.\n");
    La = L;
    printf("How many values do you want in it?\n");
    scanf("%d", &i);
    printf("Please enter %d values(user Enter to commit).\n", i);
    for (j = 0; j < i; j++) {
	scanf("%d", &e);
	ListInsert(&Lb, j+1, e);
	if (j != i - 1)
	    printf("Please enter next value:\n");
    }
    printf("Now the length of Lb is %d.\n", Lb.length);
    printf("The content of sqlist are: \n");
    ListTraverse(Lb);
    printf("Union Two sqlist now:\n");
    unionL(&La, Lb);
    ListTraverse(La);
    
    return 0;
}
