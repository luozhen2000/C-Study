#include<stdio.h>

int main()
{
	int arr[10]={0};
	printf("%p\n",arr);//数组名表示第一个元素地址
	printf("%p\n",arr+1);

	printf("%p\n",&arr[0]);
	printf("%p\n",&arr[0]+1);

	printf("%p\n",&arr);//数组名表示整个数组
	printf("%p\n",&arr+1);

	int a = 10;
	int b = 20;
	int c = 30;
	int* arr1[3]={&a,&b,&c};

	for(int i=0;i<3;i++)
	{
		printf("%d ",*arr1[i]);
	}











	return 0;
}
