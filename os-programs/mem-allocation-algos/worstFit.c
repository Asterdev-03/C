#include <stdio.h>

int main() {
	int blockSize[20],processSize[20],nob, nop, allocation[20];
    printf("Enter no. of processes: ");
	scanf("%d", &nop);
	
	printf("Enter no. of blocks: ");
	scanf("%d", &nob);
		
	printf("Enter process sizes: ");
	for(int i = 0; i < nop; i++)
		scanf("%d", &processSize[i]);
		
	printf("Enter block sizes: ");
	for(int i = 0; i < nob; i++)
		scanf("%d", &blockSize[i]);		
    
    for (int i=0; i<nop; i++)	
		allocation[i] = -1;
    for (int i=0; i<nop; i++) {
        int bestIdx = -1;
        for (int j=0; j<nob; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] < blockSize[j])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1) {   
            allocation[i] = bestIdx;   
            blockSize[bestIdx] -= processSize[i];
        }
    }

	printf("Process No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < nop; i++) {
		printf("    %d \t\t %d \t\t",i+1,processSize[i]);
        if (allocation[i] != -1)
        printf("%d",allocation[i] + 1);          
        else
			printf("Not Allocated");      
        printf("\n");
    }
	
	
	return 0;
}
