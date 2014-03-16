#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

struct node *sorted_merge(struct node* a, struct node*b);
void front_back_split(struct node *source,
                      struct node **frontp, struct node **backp);
void merge_sort(struct node **list_head);
