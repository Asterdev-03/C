#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int isKeyword(char buffer[])
{
	char keywords[32][10]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float"};
	int i,flag=0;
	for(i=0;i<32;i++)
	{
		if(strcmp(keywords[i],buffer)==0)
		{
			flag=1;
			break;
		}
	}
	return flag;
}
int main()
{
	char ch,buffer[15],operators[]="+-*/%=";
	FILE*fp;
	int i,j=0;
	fp=fopen("program.txt","r");
	if(fp==NULL)
	{
		printf("Error while opening the file\n");
		exit(0);
	}
	while((ch==fgetc(fp))!=EOF)
	{
		for(i=0;i<6;++i)
		{
			if(ch==operators[i])
			printf("%c is operator \n",ch);
		}
		if(isalnum(ch))
		{
			buffer[j++]=ch;
		}
		else if((ch==' '||ch=='\n')&&(j!=0))
		{
			buffer[j]='\O';
			j=0;
			if(isKeyword(buffer)==1)
			printf("%s is keyword\n",buffer);
			else
			printf("%s is indentifier \n",buffer);
		}
	}
	fclose(fp);
	return 0;
}
