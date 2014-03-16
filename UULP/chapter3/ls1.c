/* add some output sort */
#include <stdio.h>
#include <dirent.h>

#include <string.h>
#include <stdlib.h>

void do_ls(char []);
//int get_item_len(DIR *dir_ptr);
void print_dir(char **, int max_len);

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
	DIR *dir_ptr;				/* the directory */
	struct dirent *direntp;		/* each entry */
    int max;
    char dir_con_name[256][256];
    char **p;
    int i = 0;

    p = dir_con_name;    
    max = 0;
	if((dir_ptr = opendir(dirname)) == NULL)
		fprintf(stderr, "ls01: cannot open %s", dirname);
	else {
        /* item_len = get_item_len(dir_pr); */
		while ((direntp = readdir(dir_ptr)) != NULL) {
            /* printf("%*s", strlen(direntp->d_name)+1, direntp->d_name); */
            if (max < strlen(direntp->d_name)) {
                max = strlen(direntp->d_name);
            }
            //p[i] = malloc((strlen(direntp->d_name)) * sizeof(char));
            strcpy(p[i], direntp->d_name);
            i++;
        }
        print_dir(p, max);

		closedir(dir_ptr);
	}
}

void print_dir(char **ch, int max)
{
    char **p = ch;
    int i = 0;
    while (strcmp(p[i], NULL)) {
        printf("%*s", max, p[i]);
        i++;
    }
    /* need free */
}

/* int get_item_len(DIR *dir_ptr) */
/* { */
/*     int max; */
/*     int len; */
    
/*     max = 0; */
/*     struct dirent *direntp; */
/*     while ((direntp = readdir(dir_ptr)) != NULL) { */
/*         len = strlen(direntp->d_name); */
/*         if (len > max) { */
/*             max = len; */
/*         } */
/*     } */
/*     closedir(dir_ptr); */
/*     return max; */
/* } */
