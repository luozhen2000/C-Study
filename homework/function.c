#include<stdio.h>
#include<math.h>


//判断素数
int primejug(int num)
{
	int i = 0;
	for(i=2;i<=sqrt(num);i++)

	{
		if(num%i==0)
		{
			printf("%d不是素数\n",num);
			break;
		}
	}
	if(i>sqrt(num))
	{
		printf("%d是素数\n",num);
	}
	return 0;
}


//判断是否为闰年
void leapyear(int year)
{
	while(1)
	{
		if((year%4==0 && year%100!=00)||(year%400==0))
		{
			printf("%d是闰年\n",year);
			break;
		}
		else
		{
			printf("%d不是闰年\n",year);
			break;
		}
		
	}
}


//二分法查找数组中n的位置
void binsearch(int arr[],int n,int sz)
{
	int left = 0;
	int right = sz - 1;
	int mid = 0;	
	while(left<=right)
	{
		mid = (left+right)/2;

		if(arr[mid]==n)
		{
			printf("%d在数组中的位置是%d\n",n,mid);
			break;
		}
		if(arr[mid]>n)
		{
			right=mid-1;
		}
		if(arr[mid]<n)
		{
			left=mid+1;
		}
	}
	if(left>right)
	{
		printf("数组中没有这个数字\n");
	}
}
		
			
void add1(int *pa)
{
	//*pa++;   ++的优先级高于*，所以此时pa已经指向了下一个地址
	*pa=*pa+1;
}

//printf返回的是输出字符的数量。


	
int main()
{
	int num=0;
	printf("请输入你想要判断是否为素数的数：");
	scanf("%d",&num);
	primejug(num);
	

	int year=0;
	printf("请输入你想要判断是否为闰年的年份：");
	scanf("%d",&year);
	leapyear(year);

	int arr[]={1,3,6,7,8,9,10,14,17};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int n=0;
	printf("请输入你想要查找的数字：");
	scanf("%d",&n);
	binsearch(arr,n,sz);

	int p = 0;
	printf("请输入你想要循环的次数：");
	int times=0;
	scanf("%d",&times);
	for(int i =0;i<times;i++)
	{
		add1(&p);
	}
	printf("此时p的大小为:%d",p);


	return 0;
}

