#include "merge_sort_list.h"

void merge_sort(struct node **list_head)
{
    struct node *head = *list_head;
    struct node *a;
    struct node *b;

    /* check list length */
    if (head == NULL || (head->next == NULL)) {
        return;
    }

    /* split list into 'a' and 'b' */
    front_back_split(head, &a, &b);

    /* sort the sublists recursively */
    merge_sort(&a);
    merge_sort(&b);

    /* answer = merge the two soted lists together */
    *list_head = sorted_merge(a, b);
}

struct node *sorted_merge(struct node *a, struct node *b)
{
    struct node *result = NULL;

    /* check length */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* pick either a or b, and recur */
    if (strcmp(a->str, b->str) < 0) {
        result = a;
        result->next = sorted_merge(a->next, b);
    } else {
        result = b;
        result->next = sorted_merge(a, b->next);
    }

    return result;
}

void front_back_split(struct node *source,
                      struct node **frontp, struct node **backp)
{
    struct node *fast;
    struct node *slow;

    if (source == NULL || source->next == NULL) {
        /* length < 2 case */
        *frontp = source;
        *backp = NULL;
    } else {
        slow = source;
        fast = source->next;

        /* Advance 'fast' two nodes, and advance 'slow' one node */
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        /* 'slow' is before the midpoint in the list, so split it in two at
         that point*/
        *frontp = source;
        *backp = slow->next;
        slow->next = NULL;
    }
}
