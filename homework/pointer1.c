#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int pow1(int a,int b)
{
	int tmp = a;
	while(b>1)
	{
		a*=tmp;
		b--;
	}
	return a;
}



void reverseStr(char* str)
{
	assert(str);//判断指针有效性，无效则终止程序
	int sz = strlen(str);
	char* right = str+sz-1;
	char* left = str;
	while(left<right)
	{
		char tmp=*left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void test()
{
	int a=0;
	int n=0;
	scanf("%d%d",&a,&n);
	int sum = 0;
	int tmp = 0;
	for(int i=0;i<n;i++)
	{
		tmp = tmp*10 + a;
		sum += tmp;
	}
	printf("%d\n",sum);
}

void test1()
{

	int n=0;
	for(int i=0;i<100000;i++)
	{
		int sum=0;
		int num=1;
		/*
		if(i/1000!=0)num=4;
		else if(i/100!=0)num=3;
		else if(i/10!=0)num=2;
		else num=1;
		*/
		int tmp = i;
		while(tmp/=10)
		{
			num++;
		}
		tmp =i;
		//求每一位
		while(tmp)
		{
			sum+=pow1(tmp%10,num);
			tmp /=10;
		}
		if(i==sum)
		{
			printf("%d\n",i);
			n++;
		}
		/*
		switch(num)
		{
			case 1:
				if(i==1||i==0)
				{
					printf("%d\n",i);
					n++;
				}
				break;
			case 2:
				if(pow1(i%10,2)+pow1(i/10,2)==i)
				{
					printf("%d\n",i);
					n++;
				}
				break;
			case 3:
				if(pow1(i/100,3)+pow1((i%100)/10,3)+pow1(i%10,3)==i)
				{
					printf("%d\n",i);
					n++;
				}
				break;
			case 4:
				if(pow1(i/1000,3)+pow1((i%1000)/100,3)+pow1((i%100)/10,3)+pow1(i%10,3)==i)
				{
					printf("%d\n",i);
					n++;
				}
				break;
			default:
				break;
		}
		*/
	}
	printf("总共有%d个水仙花数\n",n);
}
				
void test3()
{
	int line=0;
	scanf("%d",&line);
	for(int i=1;i<line+1;i++)
	{
		int s=line-i;
		int n=1+(i-1)*2;
		for(int j=0;j<s;j++)
			printf(" ");
		for(int j=0;j<n;j++)
			printf("*");
		printf("\n");
	}
	for(int i=1;i<line;i++)
	{
		int s=i;
		int n=1+(line-1-i)*2;
		for(int j=0;j<s;j++)
			printf(" ");
		for(int j=0;j<n;j++)
			printf("*");
		printf("\n");
	}
}


int main()
{
	unsigned long aArr[]={6,7,8,9,10};
	unsigned long *p;
	p=aArr;
	*(p+3) +=3;

	printf("%d,%d\n",*p,*(p+3));//6,12

	char c[]={"~retsis,em rof gnitiaw esaelp"};
	printf("%s\n",c);
	reverseStr(c);
	printf("%s\n",c);

	//test();
	//test1();
	test3();


	return 0;
}
