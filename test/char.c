#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//char类型会将存入的数字自动转换为-128～127。而strlen遇到0则视为。
int main()
{
	char a[1000];
	for(int i=0;i<1000;i++)
	{
		a[i]=-1-i;
	}
	printf("%ld\n",strlen(a));
	return 0;
}
