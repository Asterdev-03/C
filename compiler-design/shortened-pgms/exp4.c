#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[])
{
	char keywords[6][10] = {"void", "break", "char", "int", "float", "return"}; // add necessary keywords

	int flag = 0;
	for (int i = 0; i < 6; i++) // provide no. of keywords used
	{
		if (strcmp(keywords[i], buffer) == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}

int main()
{
	char ch, buffer[15], operators[] = "+-*/%=";
	FILE *fp;
	int i, j = 0;

	fp = fopen("program.txt", "r");

	while ((ch = fgetc(fp)) != EOF)
	{
		for (i = 0; i < 6; ++i)
		{
			if (ch == operators[i])
				printf("%c is operator\n", ch);
		}
		if (isalnum(ch))
			buffer[j++] = ch;
		else if ((ch == ' ' || ch == '\n') && (j != 0))
		{
			buffer[j] = '\0';

			j = 0;
			if (isKeyword(buffer) == 1)
				printf("%s is keyword\n", buffer);
			else
				printf("%s is indentifier\n", buffer);
		}
	}
	return 0;
}