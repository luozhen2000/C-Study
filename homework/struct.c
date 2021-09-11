#include <stdio.h>


typedef struct 
{
	int full;
	int empty;
	int sum;
}drink;
void test1()
{
	drink d={30,0,0};
	scanf("%d",&d.full);
	while(1)
	{
		d.full+=d.empty/2;
		if(d.empty%2==0)
			d.empty=0;
		else
			d.empty=d.empty%2;
		d.empty+=d.full;
		d.sum+=d.full;
		d.full=0;
		if(d.empty==1 && d.full==0)
			break;
	}
	printf("%d\n",d.sum);
}



int main()
{
	test1();



	return 0;
}
