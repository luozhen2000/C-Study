#include<stdio.h>
#include<stdlib.h>

//回调函数就是通过函数指针调用的函数，把函数指针作为参数传递给另外一个函数，当这个指针被用来调用其所指向的函数时，这就是回调函数。


typedef struct
{
	char name[20];
	int id;
	int score;
}Stu;
//void *表示任意类型的指针
//void *类型的指针不能进行解引用操作
int cmp_Stu(const void * e1,const void * e2)
{
	if((*(Stu*)e1).score>(*(Stu*)e2).score)
		return -1;
	else if((*(Stu*)e1).score<(*(Stu*)e2).score)
		return 1;
	if(((Stu*)e1)->score==((Stu*)e2)->score)
	{
		return (*(Stu*)e1).id-(*(Stu*)e2).id;
	}
}
int cmp_int(const void* e1,const void* e2)
{
	return *(int*)e1-*(int*)e2;
}

int cmp_float(const void* e1,const void* e2)
{
	return *(float*)e1>*(float*)e2?1:-1;
}
void test_int()
{
	int arr[]={1,2,5,7,22,33,2};
	int sz= sizeof(arr)/sizeof(arr[0]);
	qsort(arr,sz,sizeof(arr[0]),cmp_int);
	for(int i=0;i<sz;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n\n");
}
void test_float()
{
	float arr[]={1.1,2.3,5.55,7.12,22.1,33.33,2.23};
	int sz= sizeof(arr)/sizeof(arr[0]);
	qsort(arr,sz,sizeof(arr[0]),cmp_float);
	for(int i=0;i<sz;i++)
	{
		printf("%f ",arr[i]);
	}
	printf("\n\n");
}
void test_Stu()
{
	Stu arr[]={{"李哥",4,120},{"张三",1,150},{"李四",2,149},{"王五",3,150}};
	int sz= sizeof(arr)/sizeof(arr[0]);
	qsort(arr,sz,sizeof(arr[0]),cmp_Stu);
	for(int i=0;i<sz;i++)
	{
		printf("%d ",(arr[i]).id);
		printf("%s ",(arr[i]).name);
		printf("%d ",(arr[i]).score);
		printf("\n");
	}
	printf("\n\n");
}
void bubble_sort0(int arr[],int sz)
{
	for(int i=0;i<sz-1;i++)
	{
		for(int j=0;j<sz-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
	}
}

void swap(char* buf1,char* buf2,int width)
{
	//由下面注释可知，此时buf1，buf2相当于char指针，故只能操作一个字符
	//而一个元素宽度为width，即有width个字符,所以需要挨个交换以达到交换整个元素的作用。
	for(int i=0;i<width;i++)
	{
		char tmp = *(buf1+i);
		*(buf1+i) = *(buf2+i);
		*(buf2+i) = tmp;
	}
}
//此冒泡排序函数可以排列任意种类的数组。
void bubble_sort(void* base,int sz,int width,int (*cmp)(const void *,const void *))
{
	for(int i=0;i<sz-1;i++)
	{
		for(int j=0;j<sz-1-i;j++)
		{
			//width为一个元素的大小，单位为字节，将base转化为char*后
			//base的单位就为1字节，此时，base+j*width就相当于把元素
			//向后移动了j个，类似于arr[0+j];
			if(cmp((char*)base+j*width,(char*)base+(j+1)*width)>0)
			{
				swap((char*)base+j*width,(char*)base+(j+1)*width,width);
			}
		}
	}
}
int main()
{
	test_int();
	test_float();
	test_Stu();
	//float arr[]={1,2,5,11,33,44,123,1,0};
	Stu arr[]={{"李哥",4,120},{"张三",1,150},{"李四",2,149},{"王五",3,150}};
	int sz= sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr,sz,sizeof(arr[0]),cmp_Stu);
	for(int i=0;i<sz;i++)
	{
		printf("%d ",(arr[i]).id);
		printf("%s ",(arr[i]).name);
		printf("%d ",(arr[i]).score);
		printf("\n");
	}
	printf("\n\n");
	return 0;
}
