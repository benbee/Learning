#define MAX_FILE_NAME_L 256

struct node {
    char str[MAX_FILE_NAME_L];
    struct node *next;
    struct node *prev;
};

struct node *init_list(); /* init the name list */
struct node *create_node(char *str);
int list_append(struct node *list, struct node *node_a,
    char *str); /*
                                                         append file name*/
int delete_node(struct node *list, struct node *node_d);
void free_list(struct node *list);
void free_node(struct node *node_f);
