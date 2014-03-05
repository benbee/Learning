#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

ino_t get_inode(char *);
void printpathto(ino_t);
void inum_to_name(ino_t, char *, int);

int main(int argc, char *argv[])
{
    printpathto(get_inode("."));
	putchar('\n');
    return 0;
}

void printpathto(ino_t this_node)
{
	ino_t my_inode;
	char its_name[BUFSIZ];
	if (get_inode("..") != this_node);
	{
		chdir("..");			/* up one dir */
		inum_to_name(this_node, its_name, BUFSIZ); /* get its name */
		my_inode = get_inode(".");
		printpathto(my_inode);
		printf("/%s", its_name);
	}
}

void inum_to_name(ino_t inode_to_find, char *namebuf, int buflen)
{
	DIR *dir_ptr;
	struct dirent *direntp;
	dir_ptr = opendir(".");
	if (dir_ptr == NULL) {
		perror(".");
		exit(1);
	}
	while ((direntp = readdir(dir_ptr)) != NULL) {
		if (direntp->d_ino == inode_to_find) {
			strncpy(namebuf, direntp->d_name, buflen);
			namebuf[buflen-1] = '\0'; /* just in case */
			closedir(dir_ptr);
			return;
		}
	}
	fprintf(stderr, "error looking for inum %d\n", inode_to_find);
	exit(1);
}
ino_t get_inode(char *fname)
/*
 * return the inode number of a file
 * */

