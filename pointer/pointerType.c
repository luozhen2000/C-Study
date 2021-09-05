#include<stdio.h>

int main()
{
	int a = 0x11223344;
	//指针占空间都是4个字节或者8个字节
	//但是指针类型限制了解引用之后能够访问多少个字节
	//例如：
	//int* 能够访问4个字节
	//char* 能够访问1个字节
	//double* 能够访问8个字节
	int* pa=&a;
	char* pc=&a;
	*pc = 0;
	printf("%d\n",a);
	*pa = 0;
	printf("%d\n",a);
	printf("%p\n",pa);
	printf("%p\n",pa+1);//后移了四个字节
	printf("%p\n",pc);
	printf("%p\n",pc+1);//后移了一个字节
	return 0;
}
