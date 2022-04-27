#include <stdio.h>

int main()
{
    char regNo[25];
    int i;

    printf("Enter Registration No. : ");
    scanf("%s", regNo);

    // check if the charachter is number b/w 2 to 7
    // since prime number digits starts at 2 and end at 7
    // checking for prime number by excluding the non prime numbers
    // which are 4 and 6 b/w 2 to 7
    // hence the only prime numbers are 2, 3, 5, 7

    for (i = 0; regNo[i] != '\0'; i++)
        if (regNo[i] == '2' || regNo[i] == '3' || regNo[i] == '5' || regNo[i] == '7')
                printf("%c\n", regNo[i]);

    return 0;
}