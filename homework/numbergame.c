#include<stdlib.h>
#include<stdio.h>
#include<time.h>
void menu()
{
	printf("*欢迎来到猜数字游戏(0-100)*\n");
	printf("***************************\n");
	printf("***1.开始游戏 0.退出游戏***\n");
	printf("***************************\n");
}

void game()
{
//生成一个随机数
//时间戳：当前时间减去1970-1-1 00:00:00
	int ret=0;
	int guess=0;
	ret = rand()%100+1;//生成一个1-100的随机数。
	while(1)
	{
		printf("猜猜数字:");
		scanf("%d",&guess);
		if(guess>ret)
			printf("猜大了\n");
		if(guess<ret)
			printf("猜小了\n");
		if(guess==ret)
		{
			printf("猜对啦！！！！！！\n");
			break;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				game();
				break;

			case 0:
				break;
			default:
				printf("请输入正确数字\n");
				break;
		}
	}while(input);
	return 0;
}
