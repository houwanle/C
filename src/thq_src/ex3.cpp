#include<stdio.h>

#define N	7

void main()
{
	int i, j;
	char alpha[N];
	char tmp;

	printf("请按ASCII码的升序输入5个字母: ");
	for(i=0; i<N-1; i++)
	{
		scanf("%c",&alpha[i]);
	}


	printf("请随机输入一个字母: ");
	scanf("%c", &tmp);
	
	i=0;
	while(tmp > alpha[i])
		i++;

	for(j=N-2; j>=i; j--)
		alpha[j+1] = alpha[j];
	alpha[i] = tmp;

	for(i=0; i<N; i++)
		printf("%c", alpha[i]);
	printf("\n");

}