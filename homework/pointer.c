#include<stdio.h>
#include<string.h>


/*
struct test
{
	int num;
	char *pcName;
	short sData;
	char cha[2];
	short sBa[4];
}*p;
*/
int main()
{
	//数组名是首元素地址
	//1. sizeof(数组名)-表示整个数组
	//2. &数组名-数组名表示整个数组
	/*
	int a[]={1,2,3,4};
	printf("%d\n",sizeof(int));
	printf("%d\n",sizeof(a));//16
	printf("%d\n",sizeof(a+0));//4--8 因为为64位系统,所以为8
	printf("%d\n",sizeof(*a));//4
	printf("%d\n",sizeof(a+1));//4--8 同上
	printf("%d\n",sizeof(a[1]));//4
	printf("%d\n",sizeof(&a));//4--8 同上
	printf("%d\n",sizeof(*&a));//16
	printf("%d\n",sizeof(&a+1));//4--8 同上 跳过了一个数组的地址
	printf("%d\n",sizeof(&a[0]));//4--8 同上
	printf("%d\n",sizeof(&a[0]+1));//4--8 同上
	*/
	
	/*
	char arrc[]={'a','b','c','d','e','f'};
	printf("%d\n",sizeof(arrc));//6
	printf("%d\n",sizeof(arrc+0));//8 
	printf("%d\n",sizeof(*arrc));//1
	printf("%d\n",sizeof(arrc[1]));//1
	printf("%d\n",sizeof(&arrc));//8
	printf("%d\n",sizeof(&arrc+1));//8
	printf("%d\n",sizeof(&arrc[0]+1));//8
	*/
	/*
	printf("%d\n",strlen(arrc));//随机 
	printf("%d\n",strlen(arrc+0));//随机 
	//printf("%d\n",strlen(*arrc));//报错
	//printf("%d\n",strlen(arrc[1]));//报错
	printf("%d\n",strlen(&arrc));//随机
	printf("%d\n",strlen(&arrc+1));//随机 为上面随机-6
	printf("%d\n",strlen(&arrc[0]+1));//随机-1
	*/
	/*
	char arr[]="abcdef";
	printf("%d\n",sizeof(arr));//7
	printf("%d\n",sizeof(arr+0));//8 
	printf("%d\n",sizeof(*arr));//1
	printf("%d\n",sizeof(arr[1]));//1
	printf("%d\n",sizeof(&arr));//8
	printf("%d\n",sizeof(&arr+1));//8
	printf("%d\n",sizeof(&arr[0]+1));//8

	printf("%d\n",strlen(arr));//6
	printf("%d\n",strlen(arr+0));//6
	//printf("%d\n",strlen(*arr));//报错
	//printf("%d\n",strlen(arr[1]));//报错
	printf("%d\n",strlen(&arr));//6
	printf("%d\n",strlen(&arr+1));//随机值
	printf("%d\n",strlen(&arr[0]+1));//5
	*/

	/*
	char *p="abcdef";
	printf("%d\n",sizeof(p));//8
	printf("%d\n",sizeof(p+1));//8 
	printf("%d\n",sizeof(*p));//7 -- 1 此时*p指向a
	printf("%d\n",sizeof(p[0]));//1
	printf("%d\n",sizeof(&p));//8
	printf("%d\n",sizeof(&p+1));//8
	printf("%d\n",sizeof(&p[0]+1));//8


	printf("%d\n",strlen(p));//6
	printf("%d\n",strlen(p+1));//5
	//printf("%d\n",strlen(*p));//报错
	//printf("%d\n",strlen(p[0]));//报错
	printf("%d\n",strlen(&p));//6
	printf("%d\n",strlen(&p+1));//随机值
	printf("%d\n",strlen(&p[0]+1));//5
	*/

	/*
	int a[3][4]={0};
	printf("%d\n",sizeof(a));//48
	printf("%d\n",sizeof(a[0][0]));//4
	printf("%d\n",sizeof(a[0]));//16
	printf("%d\n",sizeof(a[0]+1));//16--8  a[0]此时表示第一行第一个元素地址，所以+1位第二个元素地址
	printf("%d\n",sizeof(*(a[0]+1)));//4
	printf("%d\n",sizeof(a+1));//8  a+1为第二行的地址
	printf("%d\n",sizeof(*(a+1)));//16 第二行首元素的地址,也就是第二行的数组名
	printf("%d\n",sizeof(&a[0]+1));//8
	printf("%d\n",sizeof(*(&a[0]+1)));//16
	printf("%d\n",sizeof(*a));//16
	printf("%d\n",sizeof(a[3]));//16
	*/
	/*
	p = (struct test*)0x100000;
	printf("%p\n",p+0x1);
	printf("%p\n",(unsigned long)p+0x1);//p转换为十进制再+1就相当于十六进制+1，所以为0x100001
	printf("%p\n",(unsigned int*)p+0x1);//0x100004
	*/


	/*
	int a[4]={1,2,3,4};
	int *p1=(int *)(&a+1);
	int *p2 =(int *)((int)a+1);
	printf("%x,%x",p1[-1],*p2);//0x4,0x100(大端储存),0x02000000(小端存储)
	//这段代码在linux gcc中执行会报段错误
	*/

	/*
	int a[3][2]={(0,1),(2,3),(4,5)};//逗号表达式只取后面的
	int *p = a[0];
	printf("%d\n",p[0]);//1
	*/

	/*
	int a[5][5];
	int(*p)[4];
	p=a;
	printf("%p,%d\n",&p[4][2]-&a[4][2],&p[4][2]-&a[4][2]);
	//p[4][2]==*(*(p+4)+2)
	//a[5][5]相当于一共有25个int
	//a[4][2]表示第23个，而p[4][2]表示第19个
	//所以两者取地址相减应该为-4
	//而-4 补码为11111111111111111111111111111100 %p强制输出为16进制就为0xfffffffc
	//而64位系统&后是long int 类型 所以%p为0xfffffffffffffffc
	*/




	return 0;
}
