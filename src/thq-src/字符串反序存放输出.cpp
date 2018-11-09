#include <stdio.h>
#include <string.h>
#define N 50     
  char a[100];
  int i;
  void main()
  {
	void Reverse(); 
	printf("ÇëÊäÈë×Ö·û´®£º");
	scanf("%s",&a[i]);
	printf("·´×ªºóµÄ×Ö·û´®£º");
	Reverse();           
  } 
  void Reverse()
  {
	  for(i=N;i>=0;i--)
		  printf("%c ",a[i]);
	  printf("\n");
  } 
