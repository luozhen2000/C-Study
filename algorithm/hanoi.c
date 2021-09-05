#include<stdio.h>

void move(char a,char b)
{	
	printf("%c----->%c\n",a,b);
}

void hanoi(char a,char b,char c,int n)
{
	if(n>0)
	{
		hanoi(a,c,b,n-1);
		move(a,c);
		hanoi(b,a,c,n-1);
	}
}

int main()
{
	char a = 'A';
	char b = 'B';
	char c = 'C';
	int n=0;
	printf("输入你想要移动的块数:");
	scanf("%d",&n);
	hanoi(a,b,c,n);
}

