#include "list_qsort.h"

int cmp(const void *a, const void *b)
{
    return strcmp((*(struct node *)a)->str, (*(struct node *)b)->str);
}
