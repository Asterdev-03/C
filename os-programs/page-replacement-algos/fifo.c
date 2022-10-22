#include <stdio.h>
int main() {
    int noOfPages, pages[50], noOfFrames, frames[50], pageFaults = 0, frameIndex = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &noOfPages);
    printf("Enter the page number: ");
    for (int i = 0; i < noOfPages; i++)
        scanf("%d", &pages[i]);
    printf("Enter the number of frames: ");
    scanf("%d", &noOfFrames);
    for (int i = 0; i < noOfFrames; i++)
        frames[i] = -1;

    printf("ref string\t page frames\n");
    for (int i = 0; i < noOfPages; i++) {
        printf("%d\t\t", pages[i]);
        int flag = 0;
        for (int j = 0; j < noOfFrames; j++)
            if (frames[j] == pages[i])
                flag = 1;
        if (flag == 0) {
            frames[frameIndex] = pages[i];
            frameIndex = (frameIndex + 1) % noOfFrames;
            pageFaults++;
            for (int j = 0; j < noOfFrames; j++)
                printf("%d\t", frames[j]);
        }
        printf("\n");
    }
    printf("Page fault is %d", pageFaults);
    return 0;
}
