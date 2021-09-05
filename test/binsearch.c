#include<stdio.h>
#include<string.h>

//顺序遍历查找顺序数组中n的下标
int binsearch(int sz,int v[],int n)
{
	//int sz = sizeof(v)/sizeof(v[0]);
	//数组作为参数传进函数时传进来的是首元素地址，所以sizeof会报错。
	for(int j=0;j<sz;j++)
	{
		if(v[j]==n)
		{
			printf("%d",j);
			break;
		}
		if(sz==j)
		{
			printf("no n");
		}
	}
	return 0;
}
//二分法查找顺序数组中的n的下标
int binsearch2(int sz,int v[])
{
	int n = 0;
	while(1)
	{	
		printf("enter the number u want to search: ");
		scanf("%d",&n);
		if(n>v[sz-1]||n<v[0])
		{
			printf("please enter the true number\n");
		}
		else
			break;
	}

	int left = 0;
	int right = sz-1;
	//while(1)如果数组数字不连续，会导致left>right的情况，这是表示输入数字不在数组内。
	while(left<=right)//这样限定条件就不会出现上述问题
	{
		int mid = (left+right)/2;
		if(v[mid]==n)
		{
			printf("position=%d\n",mid);
			break;
		}
		if(v[mid]>n)
		{
			right = mid - 1;
		}
		if(v[mid]<n)
		{
			left = mid+1;
		}
	}
	if(left>right)
		printf("数组中没有你输入的数字\n");
	return 0;
}
int main()

{
	int i = 0;
	//for(i=0;i<10;i++)
	for(;i<10;i++)
	{
		if(5==i)//constant before variable
			//continue;
			break;
		printf("%d\n",i);
	}
	int j = 0;
	do
		printf("%d",++j);
	while(j<10);
	printf("\n");
	
	//count 1!+2!+...+n!
	int x =0;
	scanf("%d",&x);
	int sum=0;
	for(x;x>0;x--)
	{	
		int y =1;
		int z = x;
		while(z>0)//count z!
		{
			y = y*z;
			z--;
		}
		sum = sum+y;
	}
	printf("%d\n",sum);
	
	int v[] = {1,2,3,4,6,7,9,10,11};
	int sz = sizeof(v)/sizeof(v[0]);
	binsearch2(sz,v);
	return 0;
}
