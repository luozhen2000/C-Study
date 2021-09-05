#include<stdio.h>


int main()
{
	int a,b,c;
	a=5;
	c=++a;
	b=++c,c++,++a,a++;//=的优先级高于,所以此行b=++c.
	b+=a++ + c;
	printf("a=%d  b=%d  c=%d\n",a,b,c);
	return 0;
}

