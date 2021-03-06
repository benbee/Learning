#include <stdio.h>
#include <dirent.h>

void do_ls(char []);

int main(int argc, char *argv[])
{
    printf("argc: %d\n", argc);
    if (argc == 1) {
        do_ls(".");
    } else {
        while (--argc) {
            printf("%s\n", *++argv);
            do_ls(*argv);
        }
    }
    return 0;
}

void do_ls(char *dirname)
{
    DIR *dir_ptr;               /* the directory */
    struct dirent *direntp;     /* each entry */

    if((dir_ptr = opendir(dirname)) == NULL)
        fprintf(stderr, "ls01: cannot open %s", dirname);
    else {
        while ((direntp = readdir(dir_ptr)) != NULL)
            printf("%s\n", direntp->d_name);
        closedir(dir_ptr);
    }
}
