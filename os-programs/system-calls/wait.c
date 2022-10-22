#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int pid, status;
	
	pid = fork();
	
	if (pid == 0) {
		printf("Child Process\n");
		exit(0);
	} else {
		printf("Parent Process\n");
		wait(&status);
		printf("Parent Process Exiting\n");
	}
	return 0;
}
