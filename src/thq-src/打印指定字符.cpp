#include<stdio.h>
int main()
{
	void PrintChar(int n,char ch);
	int a;
	char ch;
	printf("�������ӡ����a:");
	scanf("%d",&a);
	PrintChar(a,ch);
	return 0;
}
void PrintChar(int n,char ch)
{
	int i;
	for(i=1;i<=n;i++)
		printf("ch\n");
}