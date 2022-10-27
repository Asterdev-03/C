#include <stdio.h>

int n, nf;
int in[100];
int p[50];
int hit = 0;
int i, j, k;
int pgfaultcnt = 0;

int isHit(int data)
{
    hit = 0;
    for (j = 0; j < nf; j++)
    {
        if (p[j] == data)
        {
            hit = 1;
            break;
        }
    }

    return hit;
}

int getHitIndex(int data)
{
    int hitind;
    for (k = 0; k < nf; k++)
    {
        if (p[k] == data)
        {
            hitind = k;
            break;
        }
    }
    return hitind;
}

int main()
{

    printf("\nEnter length of page reference sequence:");
    scanf("%d", &n);
    printf("\nEnter the page reference sequence:");
    for (i = 0; i < n; i++)
        scanf("%d", &in[i]);
    printf("\nEnter no of frames:");
    scanf("%d", &nf);

    int usedcnt[100];
    int least, repin, sofarcnt = 0, bn;

    pgfaultcnt = 0;
    for (i = 0; i < nf; i++)
        p[i] = 9999;

    for (i = 0; i < nf; i++)
        usedcnt[i] = 0;

    for (i = 0; i < n; i++)
    {

        printf("\n For %d :", in[i]);
        if (isHit(in[i]))
        {
            int hitind = getHitIndex(in[i]);
            usedcnt[hitind]++;
            printf("No page fault!");
        }
        else
        {
            pgfaultcnt++;
            if (bn < nf)
            {
                p[bn] = in[i];
                usedcnt[bn] = usedcnt[bn] + 1;
                bn++;
            }
            else
            {
                least = 9999;
                for (k = 0; k < nf; k++)
                    if (usedcnt[k] < least)
                    {
                        least = usedcnt[k];
                        repin = k;
                    }
                p[repin] = in[i];
                sofarcnt = 0;
                for (k = 0; k <= i; k++)
                    if (in[i] == in[k])
                        sofarcnt = sofarcnt + 1;
                usedcnt[repin] = sofarcnt;
            }

            for (k = 0; k < nf; k++)
            {
                if (p[k] != 9999)
                    printf(" %d", p[k]);
            }
        }
    }
    printf("\nTotal no of page faults:%d", pgfaultcnt);
}