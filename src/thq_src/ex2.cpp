#include<stdio.h>
int MyStrlen(char *a);
void StrtStr(char *a,char *b,char *c);
void swap(char *a,char *b);
int main()
{
	char *a,*b,*c,str1[100],str2[100],str3[100];
	int i,n1,n2,n3;
	a=str1;b=str2;c=str3;
	printf("������3���ַ���:\n");
	gets(a);gets(b);gets(c);
	n1=MyStrlen(a);
	n2=MyStrlen(b);
	n3=MyStrlen(c);
	printf("��1���ַ����ĳ���Ϊ%d\n",n1);
	printf("��2���ַ����ĳ���Ϊ%d\n",n2);
	printf("��3���ַ����ĳ���Ϊ%d\n",n3);
	StrtStr(a,b,c);
	printf("�����ַ�������������Ϊ;\n");
	printf("%s\n%s\n%s\n",a,b,c);
	return 0;
}
int MyStrlen(char *a)
{
	int i;
	for(i=0;*(a+i)!='\0';i++)
	{}
	return i;
}
void StrtStr(char *a,char *b,char *c)
{
	if(MyStrlen(a)>MyStrlen(b)) 
		swap(a,b);
	if(MyStrlen(a)>MyStrlen(c))
			swap(a,c);
	if(MyStrlen(b)>MyStrlen(c))
			swap(b,c);
}
void swap(char *a,char *b)
{
	char temp;
	int i;
	for(i=0;i<100;i++)
	{
		temp=*(a+i);
		*(a+i)=*(b+i);
		*(b+i)=temp;
	}
}