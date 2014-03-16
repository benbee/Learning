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
    node_c->next = NULL;
    node_c->prev = NULL;

    return node_c;
}

void list_append(struct node *list, struct node *node_a)
{
    struct node *p = node_a;
    p->next = list->next;
    p->prev = list;
    list->next = p;
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
    free_node(list);
}

void free_node(struct node *node_f)
{
    assert(node_f != NULL);

    free(node_f);
}

void print_list(const struct node *list)
{
    while(list->next) {
        printf("%s\n", list->next->str);
        list = list->next;
    }
}

int get_item_max_len(const struct node *list)
{
    int max = 0;

    while (list->next) {
        if (max < strlen(list->next->str)) {
            max = strlen(list->next->str);
        }
        list = list->next;
    }

    return max;
}
