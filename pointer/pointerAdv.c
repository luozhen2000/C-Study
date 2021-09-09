#include<stdio.h>



void test1()
{
	int a=0;
	int* pa=&a;//pa为指向一个int类型变量的指针。
	int* pb[10];//pb为一个长度为10，存储int指针数组。
	int* (*pc)[10];//pc指向一个长度为10，存储int类型指针的数组。
	pb[0]=pa;//将pa存储在pb这个数组的第一个元素
	pc=&pb;//将pb的地址存在pc中
	printf("%d\n",*pa);//解引用pa得到a的值
	a++;
	printf("%d\n",*pb[0]);//pb[0]存储的为pa，而pa存储的时a的地址,所以*pb[0]==a
	a++;
	printf("%d\n",***pc);//pc存储的是pb的地址,所以*pc==pb,而pb则是数组的名字也就是数组的
			     //第一个元素的地址,所以**pc==*pb也就是pb第一个元素的内容也就是pa
			     //而pa是一个指针,所以***pc==**pb==*pa==a
}
void test2()
{
	int arr1[]={1,2,3,4,5};
	int arr2[]={2,3,4,5,6};
	int arr3[]={3,4,5,6,7};
	int* parr[]={arr1,arr2,arr3};
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf("%d ",((*parr[i])+j));//解引用parr[i]得到对应arri的第1个元素
						     //但此时+j则相当于将这个int+j
		}
		printf("\n");
		for(int m=0;m<5;m++)
		{
			printf("%d ",(*(parr[i]+m)));//正确方式
		}
		printf("\n");
	}

}
void print1(int (*p)[5],int x,int y)
{
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			printf("%d ",p[i][j]);//因为arr为指向数组首元素的指针，而数组的首元素
					      //为一个含有5个int的数组，此处p与arr等价
		}
		printf("\n\n");
		for(int j=0;j<y;j++)
		{
			printf("%d ",(*(p+i))[j]);//p+i则是表示此数组中的第几个元素
		}
		printf("\n\n");
		for(int j=0;j<y;j++)
		{
			printf("%d ",*(*(p+i)+j));
		}
		printf("\n\n");
		for(int j=0;j<y;j++)
		{
			printf("%d ",*(p[i]+j));//也就是说p[i]==*(p+i)
		}
		printf("\n\n");
	}
}
int main()
{
	//test1();
	//test2();
	int arr[3][5] = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};
	//print1(arr,3,5);

	int arr1[5]={1,1,1,1,1};//arr1为一个数组
	int *parr1[5];//parr1为一个指针数组
	int (*parr2)[5];//parr2为一个数组指针
	int (*parr3[10])[5];//parr3为一个数组，存放的是int指针数组
	parr2=&arr1;
	parr3[0]=parr2;
	//parr2=&arr1;这句话必须写在前面，因为不这样的话前面一句相当于把parr3[0]变成了野指针
	for(int i=0;i<5;i++)
	{
		printf("%d ",**(parr3[0]));
	}
	printf("\n\n");
	return 0;
}
