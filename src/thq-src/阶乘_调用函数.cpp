#include<stdio.h>
int main()
{
	double GetResult(int n);
	int i;
	double s;
	printf("请输入大于等于3且小于等于50的正整数：");
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