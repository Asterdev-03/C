#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
	char path[10];
	struct stat *nfile;
	
	nfile = (struct stat *) malloc(sizeof(struct stat));
	printf("Enter file name: ");
	scanf("%s", path);
	
	stat(path, nfile);
	
	printf("User Id: %d \n", nfile->st_uid);
	printf("Group Id: %d \n", nfile->st_gid);
	printf("Size: %ld \n", nfile->st_size);
	printf("Block Size: %ld \n", nfile->st_blksize);
	printf("Mode: %d \n", nfile->st_mode);
	printf("No. of links: %ld \n", nfile->st_nlink);
	printf("Last access time: %ld \n", nfile->st_atime);
	
	return 0;
}
