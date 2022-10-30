#include <stdio.h>

int main()
{
    int np, pages[15], nf, frames[10], pagesFaults = 0, freq[10][2] = {}, nfreq = 0, pageIndx[10] = {};
    printf("Enter the number of pages: ");
    scanf("%d", &np);
    printf("Enter the pages reference numbers: ");
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &pages[i]);
        if (nfreq == 0)
            freq[nfreq++][0] = pages[i];
        else
        {
            int flag = 0;
            for (int j = 0; j < nfreq; j++)
                if (pages[i] == freq[j][0])
                {
                    flag = 1;
                    break;
                }
            if (flag == 0)
                freq[nfreq++][0] = pages[i];
        }
    }

    printf("Enter the number of frames: ");
    scanf("%d", &nf);
    for (int i = 0; i < nf; i++)
        frames[i] = -1;

    printf("ref string\t pages frames\n");
    for (int i = 0; i < np; i++)
    {
        printf("%d\t\t", pages[i]);
        int flag1 = 0;

        // pages Hit
        for (int j = 0; j < nf; j++)
            if (frames[j] == pages[i])
            {
                flag1 = 1;
                for (int k = 0; k < nfreq; k++)
                    if (freq[k][0] == pages[i])
                        freq[k][1]++;
                printf("No replacement");
                break;
            }
        if (flag1 == 0)
        {
            pagesFaults++;
            // pages Fault with Free frames
            int flag2 = 0;
            for (int j = 0; j < nf; j++)
                if (frames[j] == -1)
                {
                    frames[j] = pages[i];
                    flag2 = 1;
                    for (int k = 0; k < nfreq; k++)
                        if (freq[k][0] == pages[i])
                            freq[k][1]++;

                    pageIndx[j] = i;
                    break;
                }
            // pages Fault But No Free frames
            if (flag2 == 0)
            {
                int minfreq, frqIndx, fpos, minIndx;
                // Finding the frame index to be changed with page[i]
                for (int j = 0; j < nf; j++)
                {
                    for (int k = 0; k < nfreq; k++)
                    {
                        if (frames[j] == freq[k][0])
                        {
                            if ((j == 0) || (freq[k][1] < minfreq) || ((freq[k][1] == minfreq) && (pageIndx[j] < minIndx)))
                            {
                                minfreq = freq[k][1];
                                minIndx = pageIndx[j];
                                fpos = j;
                                frqIndx = k;
                            }
                            break;
                        }
                    }
                }

                frames[fpos] = pages[i];
                for (int j = 0; j < nfreq; j++)
                    if (freq[j][0] == pages[i])
                        freq[j][1]++;
                freq[frqIndx][1] = 0;
                pageIndx[fpos] = i;
            }
            for (int j = 0; j < nf; j++)
                printf("%d\t", frames[j]);
        }
        printf("\n");
    }
    printf("pages fault is %d", pagesFaults);

    return 0;
}