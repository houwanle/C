#include<stdio.h>

#define N	7

void main()
{
	int i, j;
	char alpha[N];
	char tmp;

	printf("�밴ASCII�����������5����ĸ: ");
	for(i=0; i<N-1; i++)
	{
		scanf("%c",&alpha[i]);
	}


	printf("���������һ����ĸ: ");
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