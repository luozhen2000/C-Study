#include <stdio.h>


int main()
{
	char a[]="abcd";
	int count=0;
	char* p=NULL;
	for(int i=0;i<8;i++)
	{
		printf("%d",(*a>>i)&1);
	}
	p=a+1;
	printf("\n");
	for(int i=0;i<8;i++)
	{
		printf("%d",(*p>>i)&1);
	}

	return 0;
}
