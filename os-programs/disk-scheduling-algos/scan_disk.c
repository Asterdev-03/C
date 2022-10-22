#include <stdio.h>
#include <stdlib.h>
int main()
{
    int reqSeq[100], noOfReq, totHeadMoment = 0, headPos;
    int leftSeq[50], rightSeq[50], leftSize = 0, rightSize = 0;
    printf("Enter initial head position: ");
    scanf("%d", &headPos);
    printf("Enter the number of Requests: ");
    scanf("%d", &noOfReq);
    printf("Enter the Requests sequence: ");
    for (int i = 0; i < noOfReq; i++) {
        int temp;
        scanf("%d", &temp);
        if(temp > headPos)
            rightSeq[rightSize++] = temp;
        else
            leftSeq[leftSize++] = temp;
    }
        
    for(int i = 0 ; i < rightSize - 1; i++)
        for(int j = i + 1; j < rightSize; j++)
            if(rightSeq[i] > rightSeq[j]) {
                int temp = rightSeq[i];
                rightSeq[i] = rightSeq[j];
                rightSeq[j] = temp;
            }

    for(int i = 0 ; i < leftSize - 1; i++)
        for(int j = i + 1; j < leftSize; j++)
            if(leftSeq[i] < leftSeq[j]) {
                int temp = leftSeq[i];
                leftSeq[i] = leftSeq[j];
                leftSeq[j] = temp;
            }

    for (int i = 0; i < leftSize; i++)
        reqSeq[i] = leftSeq[i];
    
    reqSeq[leftSize] = 0;

    for (int i = leftSize + 1, j = 0; j < rightSize; i++, j++)
        reqSeq[i] = rightSeq[j];

    for (int i = 0; i < noOfReq + 1; i++) {
        totHeadMoment = totHeadMoment + abs(reqSeq[i] - headPos);
        headPos = reqSeq[i];
    }

    printf("Seek sequence: ");
    for (int i = 0; i < noOfReq + 1; i++)
        printf("%d ", reqSeq[i]);
    printf("\nTotal head moment is %d", totHeadMoment);
    return 0;
}
