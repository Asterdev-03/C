#include <stdio.h>
#include <stdlib.h>

int main() {
	int nop, nor, alloc[20][20], avail[20], max[20][20], need[20][20], finish[20], seq[20];
	
	printf("Enter no. of processes: ");
	scanf("%d", &nop);
	
	printf("Enter no. of resource types: ");
	scanf("%d", &nor);
	
	printf("Enter values of allocated instances for each resource:\n");
	for(int i = 0; i < nop; i++)
		for(int j = 0; j < nor; j++)
			scanf("%d", &alloc[i][j]);
			
	printf("Enter values of max allocated instances for each resource:\n");
	for(int i = 0; i < nop; i++)
		for(int j = 0; j < nor; j++)
			scanf("%d", &max[i][j]);
			
	printf("Enter values of available instances for each resource: ");
	for(int i = 0; i < nor; i++)
		scanf("%d", &avail[i]);
		
	for(int i = 0; i < nop; i++)
		for(int j = 0; j < nor; j++)
			need[i][j] = max[i][j] - alloc[i][j];
			
	printf("Need matrx:\n");
	for(int i = 0; i < nop; i++) {
		for(int j = 0; j < nor; j++)
			printf("%d ", need[i][j]);
		printf("\n");
	}
			
	for(int i = 0; i < nop; i++)
		finish[i] = 0;
		
	int k = 0, flag = 1, count;	
	while(flag == 1) {
		flag = 0;
		for(int i = 0; i < nop; i++) {
			count = 0;
			if( finish[i] == 0 ) {
				for(int j = 0; j < nor; j++) 
					if(need[i][j] <= avail[j] )
						count++;											
				if(count == nor) {
					for(int j = 0; j < nor; j++) 
						avail[j] += alloc[i][j];
					finish[i] = 1;															
					flag = 1;
					seq[k++] = i + 1; 
				}			
			}
		}
	}
	
	
	for(int i = 0; i < nop; i++)
		if(finish[i] != 1) {
			printf("\nSystem not in safe state");
			exit(1);
		}
		
	printf("Sequence : ");
	for(int i = 0; i < nop; i++)
		printf("P%d->", seq[i]);
		
}
