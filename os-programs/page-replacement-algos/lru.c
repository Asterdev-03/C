#include <stdio.h>

int main() {
    int noOfPages, pages[50], noOfFrames, frames[50], pageFaults = 0, count = 0, time[50];
    printf("Enter the number of pages: ");
    scanf("%d", &noOfPages);
    printf("Enter the page number: ");
    for (int i = 0; i < noOfPages; i++)
        scanf("%d", &pages[i]);
    printf("Enter the number of frames: ");
    scanf("%d", &noOfFrames);
    for (int i = 0; i < noOfFrames; i++)
        frames[i] = -1;

    printf("ref string\t page frames\t \t time\n");
    for (int i = 0; i < noOfPages; i++) {
        printf("%d\t\t", pages[i]);
        
        int flag1 = 0;
        // Page Hit
        for (int j = 0; j < noOfFrames; j++)
            if (frames[j] == pages[i]) {
                flag1 = 1;
                count++;
                time[j] = count;
                break;
            }
        if (flag1 == 0) {
            pageFaults++;
            // Page Fault with Free Frames
            int flag2 = 0;
            for (int j = 0; j < noOfFrames; j++) 
                if(frames[j] == -1) {
                    frames[j] = pages[i];
                    flag2 = 1;
                    count++;
                    time[j] = count;                    
                    break;
                }
            // Page Fault But No Free Frames
            if(flag2 == 0) {
                int min = time[0], pos = 0;
                for (int i = 1; i < noOfFrames; i++)
                    if(time[i] < min) {
                        min = time[i];
                        pos = i;
                    }
                frames[pos] = pages[i];
                count++;
                time[pos] = count;
            }            
            for (int j = 0; j < noOfFrames; j++)
                printf("%d\t", frames[j]);
            for (int j = 0; j < noOfFrames; j++)
                printf("%d\t", time[j]);
        }
        printf("\n");
    }
    printf("Page fault is %d", pageFaults);
    return 0;
}
