#include<stdio.h>
int i;//全局变量不赋值默认为0，局部变量不赋值默认为随机数。
int main()
{
	i--;
	if(i>sizeof(i))//sizeof返回的是无符号数(unsigned int),int与其比较时被转化为无符号数。
	{
		printf(">\n");
	}
	else
	{
		printf("<\n");
	}
	printf("%u\n",(unsigned int)i);
	return 0;
}
