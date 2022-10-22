#include <stdio.h>
#include <stdlib.h>
int main()
{
    int reqSeq[100], noOfReq, totHeadMoment = 0, headPos;
    printf("Enter the number of Requests: ");
    scanf("%d", &noOfReq);
    printf("Enter the Requests sequence: ");
    for (int i = 0; i < noOfReq; i++)
        scanf("%d", &reqSeq[i]);
    printf("Enter initial head position: ");
    scanf("%d", &headPos);

    for (int i = 0; i < noOfReq; i++)
    {
        totHeadMoment = totHeadMoment + abs(reqSeq[i] - headPos);
        headPos = reqSeq[i];
    }

    printf("Total head moment is %d", totHeadMoment);
    return 0;
}
