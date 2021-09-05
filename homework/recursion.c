#include<stdio.h>
//递归求一个int各位数字之和
int DigitSum(unsigned int n)
{
	int tmp = n%10;
	n=n/10;
	if(n)
		return tmp+DigitSum(n);
	return tmp;
}
//递归求n的k次方
double Pow(int n,int k)
{
	if(k<0)
		return (1.0/Pow(n,-k));
	if(k-1)
		return n*Pow(n,k-1);
	return n;
}
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
	int a=0;
	printf("输入你想要计算的非波那契数列的第几位:");
	scanf("%d",&n);
	printf("非波那契数列第%d位为:%d\n",n,Fac(n));
	scanf("%d",&a);
	printf("%d\n",DigitSum(a));
	int b,k;
	scanf("%d %d",&b,&k);
	printf("%lf\n",Pow(b,k));
	return 0;
}
