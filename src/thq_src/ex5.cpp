#include<stdio.h>
int main()
{
	int i,a[5]={8,6,5,4,1};
	for(i=4;i>=0;i--)
	{
		a[4-i]=a[i];
		printf("%d",a[4-i]);
	}
	printf("\n");
	return 0;
}