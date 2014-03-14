#include <stdio.h>
#include "list.h"
#include <string.h>

int init_list(struct node *p)
{
    if ((p = malloc(sizeof(struct node))) != NULL) {
        p->next = p;
        p->prev = p;
        strcpy(p->str, "");
        return 1;
    } else {
        return -1;              /* error */
    }
}

int create_node(struct node *node, char *str)
{
    char *str_data;
    struct node *node_c = node;

    if ((node_c = malloc(sizeof(struct node))) == NULL) {
        printf("Alloc node error\n");
        return -1;
    } else {
        node_c->str = malloc(strlen(str) * sizeof(char));
        strcpy(node_c->str, str);
    }
}

int list_append(struct node *list, struct node *node_a,
    char *str)
{
    struct node *p = node_a;
    if (create_node(p, str)) {
        p->next = list->next;
        p->prev = list;
        list->next = p;
        return 1;
    } else {
        return -1;
    }
}

void free_list(struct node *list)
{
    struct node *p;
    struct node *q;

    p = list;

    while (p->next) {
        q = p;
        p = p->next;
        free(q->str);
        free(q);
    }
}
