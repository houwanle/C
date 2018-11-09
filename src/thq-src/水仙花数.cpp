#include<stdio.h>
int main()
{
	int IsDaffodil(int n);
	int i,m;
	for(i=100;i<=999;i++)
	{
		m=IsDaffodil(i);
		if(m==1)
			printf("%d\n",&i);
	}
	return 0;
}
int IsDaffodil(int n)
{
	int a,b,c;
	a=n/100;
	b=(n-a*100)/10;
	c=n-a*100-10*b;
	if(n==a*a*a+b*b*b+c*c*c)
		return 1;
	else
		return 0;
}