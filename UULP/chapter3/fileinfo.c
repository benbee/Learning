/* fileinfo.c -- Use stat() to obtain and print file properties
 *            -- some membuers are just numbers..
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat info;			/* buffer for file info */

	if (argc > 1)
		if (stat(argv[1], &info) != -1) {
			show_stat_info(argv[1], &info);
			return 0;
		} else
			perror(argv[1]);
	
    return 1;
}

show_stat_info(char *filename, struct stat *buf)
/*
 * Display some info from stat in a name=value format
 */
{
	printf("    mode: %o\n", buf->st_mode); /* type + mode */
	printf("   links: %d\n", buf->st_nlink); /* #links */
	printf("    user: %d\n", buf->st_uid);	 /* user id */
	printf("   group: %d\n", buf->st_gid);	 /* group id */
	printf("    size: %d\n", buf->st_size);	 /* file size */
	printf(" modtime: %d\n", buf->st_mtime); /* modified time */
	printf("    name: %s\n", filename);		 /* file name */
}	
