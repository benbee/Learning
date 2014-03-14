struct node {
    char *str;
    struct node *next;
    struct node *prev;
};

int init_list(struct node *p); /* init the name list */
int creat_node(struct node *p, char *str);
int list_append(struct node *list, struct node *node_a,
    char *str); /*
                                                         append file name*/
int delete_node(struct node *list, struct node *node_d);
void free_list(struct node *list);
