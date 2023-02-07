#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *f1, *f2, *f3, *f4;
    int locctr = 0, startaddr = 0;
    char label[10], mnemonic[10], operand[10], opcode[10], machlan[10];

    f1 = fopen("input.txt", "r");
    f2 = fopen("symtab.txt", "w");
    f3 = fopen("intermediate.txt", "w");

    fscanf(f1, "%s%s%s", label, mnemonic, operand);

    if (strcmp(mnemonic, "START") == 0)
    {
        startaddr = atoi(operand);
        locctr = startaddr;
        fprintf(f3, "\t\t%s\t%s\t%s\n", label, mnemonic, operand);
        fscanf(f1, "%s%s%s", label, mnemonic, operand);
    }

    while (!feof(f1))
    {
        fprintf(f3, "%d\t%s\t%s\t%s\n", locctr, label, mnemonic, operand);

        if (strcmp(label, "-") != 0)
            fprintf(f2, "%s\t%d\n", label, locctr);

        f4 = fopen("optab.txt", "r");
        fscanf(f4, "%s%s", opcode, machlan);

        while (!feof(f4))
        {
            if (strcmp(mnemonic, opcode) == 0)
            {
                locctr += 3;
                break;
            }
            fscanf(f4, "%s%s", opcode, machlan);
        }
        fclose(f4);

        if (strcmp(mnemonic, "RESW") == 0)
            locctr += 3 * atoi(operand);
        else if (strcmp(mnemonic, "RESB") == 0)
            locctr += atoi(operand);
        else if (strcmp(mnemonic, "WORD") == 0)
            locctr += 3;
        else if (strcmp(mnemonic, "BYTE") == 0)
        {
            if (operand[0] == 'X')
                locctr += 1;
            else
                locctr += strlen(operand) - 3;
        }

        fscanf(f1, "%s%s%s", label, mnemonic, operand);
    }

    if (strcmp(mnemonic, "END") == 0)
        printf("Program Length: %d", locctr - startaddr);

    fclose(f1);
    fclose(f2);
    fclose(f3);

    return 0;
}