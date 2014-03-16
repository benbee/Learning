#define MAX_FILE_NAME_L 256

struct node {
    char str[MAX_FILE_NAME_L];
    struct node *next;
    struct node *prev;
};

struct node *init_list(); /* init the name list */
struct node *create_node(char *str);

void list_append(struct node *list, struct node *node_a);/*append file name*/
void free_list(struct node *list);
void free_node(struct node *node_f);
void print_list(const struct node *list);
int get_item_max_len(const struct node *list);
