/* add some output sort */
#include <stdio.h>
#include <dirent.h>

#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>          /* get current terminal width */

//#include "list.h"
#include "merge_sort_list.h"

int LINE_LEN;             /* max characters in one line of terminal */
int r_flag = 0;
int a_flag = 0;



void do_ls(char [], struct node *list);
void list_ls(const struct node *list);
void handle_argv(const int argc,const char *argv[]);

int main(int argc, char *argv[])
{
    struct node *file_list;
    struct node *p;
    int max_item_len;

    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    LINE_LEN = w.ws_col;
    printf("Line Length: %d\n", LINE_LEN);

    file_list = init_list();
    file_list->next = NULL;

    printf("argc: %d\n", argc);
    handle_argv(argc, argv);

    printf("a_flag: %d\nr_flag: %d\n", a_flag, r_flag);

    if (argc == 1) {
        do_ls(".", file_list);
    } else {
        while (--argc) {
            printf("%s\n", *++argv);
            do_ls(*argv, file_list);
        }
    }

    //print_list(file_list);
    //printf("Max item length: %d", get_item_max_len(file_list));
    free_list(file_list);
    return 0;
}

void do_ls(char *dirname, struct node *list)
{
    DIR *dir_ptr;               /* the directory */
    struct dirent *direntp;     /* each entry */
    struct node *p;

    if((dir_ptr = opendir(dirname)) == NULL)
        fprintf(stderr, "ls01: cannot open %s", dirname);
    else {
        while ((direntp = readdir(dir_ptr)) != NULL) {
            /* printf("To be appened:%s\n", direntp->d_name); */
            p = create_node(direntp->d_name);
            //printf("p->str: %s\n", p->str);
            list_append(list, p);
            //printf("Appended: %s\n", p->str);
        }
        merge_sort(&list);
        list_ls(list);
    }

    closedir(dir_ptr);
}


void list_ls(const struct node *list)
{
    struct node *p;
    int max = get_item_max_len(list);
    int line_left = LINE_LEN;

    p = list->next;
    while (p) {
        if (p->str[0] == '.'){
            p = p->next;
            continue;
        }

        if (line_left > max) {
            printf("%-*s", max+1, p->str);
            line_left -= max + 1;
            p = p->next;
        } else {
            printf("\n");
            line_left = LINE_LEN;
        }
    }
}

void handle_argv(int argc, char *argv[])
{
    int ch;

    while ((ch = getopt(argc, argv,"arl")) != -1) {
        switch (ch) {
        case 'a':
            a_flag = 1;
            break;
        case 'r':
            r_flag = 1;
            break;
        case 'l':
            break;
        default:
            printf("Wrong argv!\n");
        }

    }
}
