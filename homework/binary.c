#include<stdio.h>




//count1~3 三种方法计算二进制中1的个数
int count1(unsigned int n)//用unsigned int 将n变为无符号数，这样负数也可以求出。
{
	int count =0;
	while(n)
	{
		if(n%2==1)
		{
			count++;
		}
		n=n/2;
	}
	return count;
}
int count3(int n)
{
	int count =0;
	while(n)
	{
		n=n&(n-1);//n每次&(n-1)都会让最右边的1消失
		count++;
	}
	return count;
}
int count2(int n)
{
	int count=0;
	int i=0;
	while(i<32)
	{
		if(n&1==1)
		{
			count++;
		}
		n=n>>1;
		i++;
	}
	return count;
}
//计算两个int中二进制不同的位有多少
int countd(int m,int n)
{
	int tmp=m^n;//异或
	int count=0;
	return count = count3(tmp);
}

//分别打印出一个int中奇数位和偶数位 &1为计算一个值的二进制的方法。
void print(int n)
{
	int i=0;
	printf("完整二进制为:");
	for(i=31;i>=0;i--)
	{
		printf("%d",(n>>i)&1);
	}
	printf("\n");
	printf("奇数位为:");
	for(i=30;i>=0;i-=2)
	{
		printf("%d",(n>>i)&1);
	}
	printf("\n");
	printf("偶数位为:");
	for(i=31;i>=1;i-=2)
	{
		printf("%d",(n>>i)&1);
	}
	printf("\n");
}

int main()
{
	printf("输入想要统计的数字:");
	int n;
	scanf("%d",&n);
	int count = count1(n);
	printf("count = %d\n",count);
	int countn = count2(n);
	printf("countn = %d\n",countn);
	int countx = count3(n);
	printf("countx = %d\n",countx);
	int m,i;
	scanf("%d%d",&m,&i);
	int countnn = countd(m,i);
	printf("countnn = %d\n",countnn);
	print(n);
	return 0;
}
