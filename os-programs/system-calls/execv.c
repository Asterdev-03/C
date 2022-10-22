#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	
	int pid, status;
	char *args[] = {"ls",NULL};
	
	pid = fork();
	
	if (pid == 0) {
		printf("Child Process\n");
		execv("/bin/ls",args);
	} else {
		printf("Parent Process\n");
		wait(&status);
		printf("Parent Process Exiting\n");
	}
	return 0;
}
