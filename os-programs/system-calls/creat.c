#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{	
	int fid = creat("file.dat", S_IREAD/S_IWRITE);
	
	if(fid == -1)
		printf("File not found");
	printf("File read\n");
	close(fid);
	
	return 0;
}
