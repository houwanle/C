#include<stdio.h>
int main()
{
	int i,j;
	char data1[10],data2[10];
	printf("请输入10个正整数：\n");
	for(i=0;i<10;i++)
		scanf("%d",&data1[i]);
	for(j=0;j<10;j++)
		for(i=0;i<10;i++)
		{
			if (data1[i]%2!=0)
			{
				data2[j]=data1[i];
				break;
			}
			else
			{
				data1[j]=data1[i];
				break;
			}
		}
			puts(data1);
			puts(data2);
			return 0;
}
