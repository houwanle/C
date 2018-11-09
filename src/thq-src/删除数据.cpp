#include<stdio.h>
#define LEN 10
int main()
{
    int data1[LEN], data2[LEN];
	int i, j, k, len = LEN;
	printf("请输入10个正整数: ");
	for(i=0; i<10; i++)
		scanf("%d", &data1[i]);
	for(i=0,k=0; i<10; i++)
	{
		if(data1[i]%2 == 1) 
		{
			data2[k++] = data1[i];
			for(j=i; j<10; j++)
				data1[j] = data1[j+1];
			i--;
			len--;
			
		}
	}
	printf("data1中的数据为: ");
	for(i=0;i<len; i++)
		printf("%d", data1[i]);
	printf("\n");
    printf("data2中的数据为: ");
	for(i=0;i<k; i++)
		printf("%d", data2[i]);
	printf("\n");
	return 0;
}