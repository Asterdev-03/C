#include <stdio.h>
#include <unistd.h>

int main()
{
	for(int i = 0; i < 2; i++) {
		printf("Hello %d \n", fork());
	}
	return 0;
}
