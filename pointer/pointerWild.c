#include<stdio.h>


int* test()
{
	int a=10;
	return &a;
}
int main()
{
	int* p=test();//该内存已经被释放，所以p成为了野指针
	*p = 20;
	int* p=NULL;//实在不知道赋值什么时赋值NULL来避免成为野指针
	return 0;
}
