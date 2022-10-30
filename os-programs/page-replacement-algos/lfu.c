#include <stdio.h>

int main()
{
    int np, pages[15], nf, frame[10], pagesFaults = 0, freq[10][2] = {}, fsize = 0, pageind[10];
    printf("Enter the number of pages: ");
    scanf("%d", &np);
    printf("Enter the pages reference numbers: ");
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &pages[i]);
        if (fsize == 0)
            freq[fsize++][0] = pages[i];
        else
        {
            int flag = 0;
            for (int j = 0; j < fsize; j++)
                if (pages[i] == freq[j][0])
                {
                    flag = 1;
                    break;
                }
            if (flag == 0)
                freq[fsize++][0] = pages[i];
        }
    }

    printf("Enter the number of frame: ");
    scanf("%d", &nf);
    for (int i = 0; i < nf; i++)
        frame[i] = -1;

    printf("ref string\t pages frame\n");
    for (int i = 0; i < np; i++)
    {
        printf("%d\t\t", pages[i]);

        int flag1 = 0;
        // pages Hit
        for (int j = 0; j < nf; j++)
            if (frame[j] == pages[i])
            {
                flag1 = 1;
                for (int k = 0; k < fsize; k++)
                    if (freq[k][0] == pages[i])
                        freq[k][1]++;
                printf("No replacement");
                break;
            }
        if (flag1 == 0)
        {
            pagesFaults++;
            // pages Fault with Free frame
            int flag2 = 0;
            for (int j = 0; j < nf; j++)
                if (frame[j] == -1)
                {
                    frame[j] = pages[i];
                    flag2 = 1;
                    for (int k = 0; k < fsize; k++)
                        if (freq[k][0] == pages[i])
                            freq[k][1]++;

                    pageind[j] = i;
                    break;
                }
            // pages Fault But No Free frame
            if (flag2 == 0)
            {
                int minfreq, frqind, pos, minpos;
                for (int j = 0; j < nf; j++)
                {
                    for (int k = 0; k < fsize; k++)
                    {
                        if (frame[j] == freq[k][0])
                        {
                            if ((j == 0) || (freq[k][1] < minfreq) || ((freq[k][1] == minfreq) && (pageind[j] < minpos)))
                            {
                                minfreq = freq[k][1];
                                minpos = pageind[j];
                                pos = j;
                                frqind = k;
                            }
                            break;
                        }
                    }
                }
                frame[pos] = pages[i];
                for (int k = 0; k < fsize; k++)
                    if (freq[k][0] == pages[i])
                        freq[k][1]++;
                freq[frqind][1] = 0;
                pageind[pos] = i;
            }
            for (int j = 0; j < nf; j++)
                printf("%d\t", frame[j]);
        }
        printf("\n");
    }
    printf("pages fault is %d", pagesFaults);

    return 0;
}