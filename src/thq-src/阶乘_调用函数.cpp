#include<stdio.h>
int main()
{
	double GetResult(int n);
	int i;
	double s;
	printf("��������ڵ���3��С�ڵ���50����������");
	scanf("%d",&i);
	s=GetResult(i);
	printf("s=%d\n",s);
	return 0;
}
double GetResult(int n)
{
	double x,y=1,z=0;
	for(x=1;x<=n;x++)
	{
		y=y*x;
		z=z+y;
	}
	return z;
}