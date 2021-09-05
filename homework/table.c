#include <stdio.h>
//打印乘法表
void print(int n)
{
	int i=0;
	for(i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			printf("%d*%d=%-3d ",i,j,i*j);
		}
		printf("\n");
	}
}


int main()
{
	int n=0;
	scanf("%d",&n);
	print(n);
	return 0;
	
}
