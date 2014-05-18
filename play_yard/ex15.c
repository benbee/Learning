#include <stdio.h>

int main(int argc, char *argv[])
{
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };

    /* safely get the size of ages */
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    /* first way using indexing */
    for (i = 0; i < count; i++) {
        printf("%s had %d years alive.\n", names[i], ages[i]);
    }

    printf("---\n");

    int *cur_age = ages;
    char **cur_name = names;
    /* second way using pointers */
    for (i = 0; i < count; i++) {
        printf("%s is %d years old.\n", *(cur_name+i), *(cur_age+i));
    }

    printf("---\n");

    /* third way, pointers are just arrays */
    for (i = 0; i < count; i++) {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }

    printf("---\n");

    for (cur_name = names, cur_age = ages;
         (cur_age - ages) < count;
         cur_age++, cur_name++) {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }

    char *namen = &names[0][0];
    printf("%c\n", *(namen+5));

    return 0;
}
