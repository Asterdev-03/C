#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *f1, *f2, *f3, *f4;
    int locctr, symloc, flag1, flag2;
    char label[10], mnemonic[10], operand[10], objcode[10], opcode[10], machlan[10], symname[10], str[10];

    f1 = fopen("intermediate.txt", "r");
    f2 = fopen("symtab.txt", "r");
    f3 = fopen("optab.txt", "r");
    f4 = fopen("output.txt", "w");

    fscanf(f1, "%s%s%s", label, mnemonic, operand);

    if (strcmp(mnemonic, "START") == 0)
    {
        fprintf(f4, "%s\t%s\t%s\n", label, mnemonic, operand);
        fscanf(f1, "%d%s%s%s", &locctr, label, mnemonic, operand);
    }

    while (strcmp(mnemonic, "END") != 0)
    {
        rewind(f3);
        flag1 = 0;

        fscanf(f3, "%s%s", opcode, machlan);
        while (!feof(f3))
        {
            if (strcmp(mnemonic, opcode) == 0)
            {
                flag1 = 1;
                break;
            }
            fscanf(f3, "%s%s", opcode, machlan);
        }

        if (flag1 == 1)
        {
            flag2 = 0;
            rewind(f2);
            while (!feof(f2))
            {
                fscanf(f2, "%s%d", symname, &symloc);
                if (strcmp(symname, operand) == 0)
                {
                    flag2 = 1;
                    break;
                }
            }

            if (flag2 == 1)
            {
                sprintf(str, "%d", symloc);
                strcpy(objcode, strcat(machlan, str));
            }
        }
        else if (strcmp(mnemonic, "WORD") == 0)
            strcpy(objcode, operand);
        else if (strcmp(mnemonic, "BYTE") == 0)
        {
            strcpy(str, "\0");
            char str2[10];
            for (int i = 2; i < strlen(operand) - 1; i++)
            {
                sprintf(str2, "%d", operand[i]);
                strcpy(str, strcat(str, str2));
            }
            strcpy(objcode, str);
        }
        else
            strcpy(objcode, "\0");

        fprintf(f4, "%s\t%s\t%s\t%d\t%s\n", label, mnemonic, operand, locctr, objcode);
        fscanf(f1, "%d%s%s%s", &locctr, label, mnemonic, operand);
    }
    fprintf(f4, "%s\t%s\t%s\t%d\n", label, mnemonic, operand, locctr);

    fclose(f1);
    fclose(f2);
    fclose(f3);

    return 0;
}