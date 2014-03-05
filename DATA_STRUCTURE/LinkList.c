#include <stdio.h>

#define ERROR  0
#define OK     1
#define TRUE   1
#define FALSE  0
#define NULL   ((void *)0)

typedef int ElemType;
typedef int Status;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LinkList;	/* define LinkList */


Status GetElem (LinkList L, int i, ElemType *e)
{
    int j;
    LinkList p;

    j = 1;
    p = L->next;
    while (j < i && p != NULL) {
	p = p->next;
	j++;
    }
    if (j > i || !p) {
	return ERROR;
    }
    *e =  p->data;

    return OK;
}

Status ListInsert (LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p, s;

    p = *L;
    j = 1;
    while (j < i && p) {
	p = p->next;
	j++;
    }
    if (j > i || !p) {
	return ERROR;
    }

    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p, q;
    j = 1;

    while (j < i && p->next) {
	p = p->next;
	j++;
    }

    if (j > i || !(p->next))
	return ERROR;
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}
