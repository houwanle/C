/*
写一个函数，输入一行字符，将此字符串中最长的单词输出
*/
#include <stdio.h>
#include <string.h>
int main()
{
	int str(char);
    int longest(char []);
	int i;
	char line[100];
		printf("input one line:\n");
		gets(line);
		printf("The longest word is :");
	for (i=longest(line);str(line[i]);i++)
		printf("%c",line[i]);
	  printf("\n");
	return 0;
}

int str(char c)
{
	if ((c>='a' && c<='z')||(c>='A'&&c<='z'))
	return(1);
	else
	return(0);
}

int longest(char string[])
{
	int len=0,i,length=0,flag=1,place=0,point;
	for (i=0;i<=strlen(string);i++)
	if (str(string[i]))
		if (flag)
		{
			point=i;
			flag=0;
		}
		else
			len++;
   else
     {
	   flag=1;
      if (len>=length)
		{
		  length=len;
		  place=point;
		  len=0;
	  }
     }
 return(place);
}
