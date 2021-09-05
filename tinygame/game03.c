#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
void init(char arr[ROW][COL])//init the board
{
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			arr[i][j]=' ';
		}
	}
}

void refresh(char arr[ROW][COL])//refresh the board
{
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			printf(" %c |",arr[i][j]);
		}
		if(i<ROW)
			printf("\n--- --- ---\n");
	}
}

void botRound(char arr[ROW][COL])//bot's round to go
{
	printf("电脑的回合:>\n");
	int seed=0;
	srand((unsigned int)time(NULL));
	while(1)
	{
		seed=rand()%(ROW*COL)+1;
		if(arr[seed/ROW][(seed%ROW-1)]!=' ')
			continue;
		else
		{
			arr[seed/ROW][(seed%ROW-1)] = '#';
			refresh(arr);
			break;
		}
	}
}
int isWin(char arr[ROW][COL])//jug the end
{
	if((arr[0][0]==arr[1][1])&&(arr[1][1]==arr[2][2])&&arr[0][0]!=' ')
		return 1;
	if((arr[0][2]==arr[1][1])&&(arr[1][1]==arr[2][0])&&arr[1][1]!=' ')
		return 1;
	for(int i=0;i<3;i++)
	{
		if((arr[i][0]==arr[i][1])&&(arr[i][1]==arr[i][2])&&arr[i][1]!=' ')
			return 1;
		if((arr[0][i]==arr[1][i])&&(arr[1][i]==arr[2][i])&&arr[1][i]!=' ')
			return 1;
	}
	return 0;
}

int isFull(char arr[ROW][COL])//jug whether the board is full
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(arr[i][j]==' ')
				return 0;
		}
	}
	return 1;
}
void playerRound(char arr[ROW][COL])
{
	int point=0;
	while(1)
	{
		printf("请选择你要下的位置(请选择1-9，从左往右，从上到下):>");
		scanf("%d",&point);
		if((point>9)||(point<1)||arr[point/3][(point%3-1)]!=' ')
		{
			printf("请选择正确的位置!\n");
			continue;
		}
		else
		{
			arr[point/3][(point%3-1)] = '*';
			refresh(arr);
			break;
		}
	}
}
void game()//the game road
{
	char arr[ROW][COL];
	init(arr);
	while(1)
	{
		playerRound(arr);
		if(isWin(arr)==1)
		{
			printf("恭喜你赢了！\n");
			break;
		}
		if(isFull(arr)==1)
		{
			printf("平局！\n");	
			break;
		}
		botRound(arr);
		if(isWin(arr)==1)
		{
			printf("很遗憾你输了！\n");
			break;
		}
		if(isFull(arr)==1)
		{
			printf("平局！\n");	
			break;
		}
	}
}
void menu()
{
	int n=0;
	printf("*******************\n");
	printf("***1.game 2.exit***\n");
	printf("*******************\n");
	printf("请选择:>");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("请输入正确的选择！\n");
			menu();
			break;
	}
}

int main()
{
	menu();
	return 0;
}












