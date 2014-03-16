#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_string(char *);

int main(int argc, char *argv[])
{
    struct node *list;
    struct node *p;

    list = init_list();
    p = create_node("HOHO_NOWARNING\n");
    list_append(list, p);
    p = create_node("second");
    list_append(list, p);

    /* printf("%s\n", list->str); */
    /* printf("%s", p->str); */
    print_list(list);

    //free_node(p);
    //free(p);
    free_list(list);

    return 0;
}

void print_string(char *str)
{
    printf("%s\n", str);
}
