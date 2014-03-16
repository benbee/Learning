#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_string(char *);

int main(int argc, char *argv[])
{
    struct node *list;
    struct node *p;

    list = init_list();
    //list_append(list, p, "HOHO_NOWARNING\n");

    printf("%s", list->str);

    //free_node(p);
    free(p);

    return 0;
}

void print_string(char *str)
{
    printf("%s\n", str);
}
