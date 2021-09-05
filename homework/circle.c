#include<stdio.h>
#include<math.h>
	
//求i与j之间的所有素数
int getprime(int i,int j)
{
	while(i++<j)
	{
		int count = 0;
		for(count=2;count<=sqrt(i);count++)
		{
			if(i%count==0)
			{
				break;
			}
		}
		if(count>sqrt(i))
		{
			printf("%d 是素数\n",i);
		}
	}
	return  0;
}


//求1/1-1/2+1/3.....1/n的和
int flag(int i)
{
	int j = 0;
	double sum = 0.0;
	int flag = 1;
	for(j=1;j<=i;j++)
	{
		sum +=flag*1.0/j;
		flag = -flag;
	}
	printf("1/1-1/2+1/3-1/4......1/n=%lf\n",sum);
	return 0;
}

int getmax(int sz,long arr[])
{
	int flag=0;
	for(int i=0;i<=sz-1;i++)
	{
		if(arr[i]>arr[i+1])
		{
			flag = arr[i+1];
			arr[i+1] = arr[i];
			arr[i] = flag;
			if(i>=1)
			{
				i =i-2;
			}
			
		}
	}
	for(int j=0;j<=sz-1;j++)
	{
		printf("%ld ",arr[j]);
	}
	return 0;
}
	
int main()
{
/*
	int i,j,n=0;
	printf("请输入你想要计算素数的区间:");
	scanf("%d%d",&i,&j);
	getprime(i,j);
	printf("\n");
	printf("请输入n的大小:");

	scanf("%d",&n);
	flag(n);
*/
	printf("%ld\n%ld\n",sizeof(int),sizeof(long));
	long arr[10]={};
	printf("%ld\n",sizeof(arr));
	printf("请输入你要排序的长度10的数组:");
	for(int i =0;i<10;i++)
	{
		scanf("%ld",&arr[i]);
	}
	int sz = sizeof(arr)/sizeof(arr[0]);
	getmax(sz,arr);
	return 0;
}
