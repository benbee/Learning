#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

struct node *init_list(void)
{
    struct node *q;
    q = create_node("list start");

    return q;
}

struct node *create_node(char *str)
{
    struct node *node_c;
    node_c = malloc(sizeof(struct node));
    strcpy(node_c->str, str);

    return node_c;
}

int list_append(struct node *list, struct node *node_a, char *str)
{
    struct node *p = node_a;

    p = create_node(str);
    p->next = list->next;
    p->prev = list;
    list->next = p;

    return 0;
}

void free_list(struct node *list)
{
    struct node *p;
    struct node *q;

    p = list->next;

    while (p) {
        q = p;
        p = p->next;
        free_node(q);
    }
}

void free_node(struct node *node_f)
{
    assert(node_f != NULL);

    free(node_f);
}
