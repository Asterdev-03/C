#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
	struct dirent *dptr;
	DIR *dir;
	char buff[50];
	
	printf("Enter directory: ");
	scanf("%s", buff);
	
	dir = opendir(buff);
	while(dptr = readdir(dir))
		printf("%s\n", dptr->d_name);
	closedir(dir);
	
	return 0;
}
