#include<stdio.h>


int Fac(int n)
{
	if(n<1)
	{
		return 0;
	}
	else if(n<3)
	{
		return 1;
	}
	else
	{
		return Fac(n-1)+Fac(n-2);
	}
}

int main()
{
	int n=0;
	printf("输入你想要计算的非波那契数列的第几位:");
	scanf("%d",&n);
	printf("非波那契数列第%d位为:%d\n",n,Fac(n));
	return 0;
}
