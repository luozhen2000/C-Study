#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int ROW=0;
int COL=0;
int NUM=0;
int SNUM=0;
int flag=0;
//根据难度来生成不可见地图
/*
int initBack(int difficulty,int board,int *NUM)
{
	switch(difficulty)
	{
		case 1:
			*ROW=9;
			*COL=9;
			*NUM=10;
			break;
		case 2:
			*ROW=16;
			*COL=16;
			*NUM=40;
			break;
		case 3:
			*ROW=30;
			*COL=16;
			*NUM=99;
			break;
		case 4:
			*ROW,*COL,*NUM=0;
			printf("请输入你想要设置的长宽以及地雷数:");
			scanf("%d",&ROW);
			scanf("%d",&COL);
			scanf("%d",&NUM);
			break;
	}
	int board[*ROW][*COL]={0};
	srand((unsigned)time(NULL));
	int seedROW,seedCOL=0;
	for(int i=0;i<*NUM;i++)
	{
		seedROW=rand()%*ROW+1;
		seedCOL=rand()%*COL+1;
		board[seedROW][seedCOL]=1;
	}

}
*/
void init(char frontBoard[ROW][COL])
{
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			frontBoard[i][j]=' ';
		}
	}
	for(int x=0;x<10;x++)
	{
		frontBoard[0][x]='F';
		frontBoard[x][0]='F';
		frontBoard[10][x]='F';
		frontBoard[x][10]='F';
	}

}


//刷新地图
void refresh(int frontBoard[ROW][COL],int flag)
{
	printf("剩余flag数:%d\n",flag);
	for(int i=1;i<ROW-1;i++)
	{
		for(int j=0;j<COL-1;j++)
		{
			printf(" _");
			if(j==COL-2)printf(" \n");
		}
		if(i<ROW-2)
		{
			for(int x=0;x<COL;x++)
			{
				printf("|%c",frontBoard[i][x]);
				if(x=COL)printf("|\n");
			}
		}
	}


}
int checkMine(int row,int col,int backBoard[ROW][COL])
{
	int count=0;
	for(int i=row-1;i<row+2;i++)
	{
		for(int j=col-1;j<col+2;j++)
		{
			if(backBoard[i][j]==1)
				count++;
		}
	}
	return count;
}

int check(char frontBoard[ROW][COL],char backBoard[ROW][COL],int row,int col)
{
	
	if(frontBoard[row][col]==' ')
	{
		int mine=checkMine(row,col,backBoard);
		if(mine==0)
		{
			frontBoard[row][col]='0';
			for(int i=row-1;i<row+2;i++)
			{
				for(int j=col-1;j<col+2;j++)
				{
					check(frontBoard,backBoard,i,j);
				}
			}
		}
		else
			//int类型+48也就是char类型的'0'
			frontBoard[row][col]=mine+48;
	}
	else
		return 0;
}
int isWin(int backBoard[ROW][COL],int frontBoard[ROW][COL])
{
	int count;
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			if(backBoard[i][j]==0)
			{
				if((frontBoard[i][j]!=' ')&&(frontBoard[i][j]!='F'))
					count++;
			}
		}
	}
	if(count==SNUM)
		return 1;
	else
		return 0;
}
int round(char frontBoard[ROW][COL],char backBoard[ROW][COL])
{
	int input,row,col =0;
	printf("请选择你的下一步行动\n");
	printf("1.go 2.setFlag 3.cancelFlag\n");
	printf(":>");
	scanf("%d",&input);
	switch(input)
	{
		case 1:
			printf("请选择你下一步行动的位置(行，列):");
			scanf("%d",&row);
			scanf("%d",&col);
			if(((row<1)||(row>ROW-2))
			||((col<1)||(col>COL-2)))
			{
				printf("请选择正确的位置\n");
				round(frontBoard,backBoard);
				break;
			}

			if(backBoard[row][col]==1)
			{
				return 0;
			}
			else
			{
				check(backBoard,frontBoard,row,col);
				if(isWin(backBoard,frontBoard)==1)
				{
					return 1;
				}
			}
				
			break;
		case 2:
			printf("请选择你下一步行动的位置(行，列):");
			scanf("%d",&row);
			scanf("%d",&col);
			if(((row<1)||(row>ROW-2))
			||((col<1)||(col>COL-2)))
			{
				printf("请选择正确的位置\n");
				round(char frontBoard[ROW][COL],char backBoard[ROW][COL]);
				break;
			}
			frontBoard[row][col]='F';
			flag--;
			if(isWin(backBoard,frontBoard)==1)
			{
				return 1;
			}

			break;
		case 3:
			printf("请选择你下一步行动的位置(行，列):");
			scanf("%d",&row);
			scanf("%d",&col);
			if(((row<1)||(row>ROW-2))||((col<1)||(col>COL-2))||(frontBoard[row][col]!='F'))
			{
				printf("请选择正确的位置\n");
				round(frontBoard,backBoard);
				break;
			}
			else
			{
				frontBoard[row][col]=' ';
				flag--;
			}
			break;
		default:
			printf("请选择正确的行动\n");
			round(frontBoard,backBoard);
			break;
	}
}

void menu1()
{
	int difficulty = 0;
        printf("*********************************\n");
        printf("*******1.简单 2.中等 3.困难******\n");
        printf("*********************************\n");
	printf("请选择你的难度:>");
	scanf("%d",&difficulty);
	switch(difficulty)
	{
		case 1:
			ROW=11;
			COL=11;
			NUM=10;
			break;
		case 2:
			ROW=18;
			COL=18;
			NUM=40;
		case 3:
			ROW=32;
			COL=18;
			NUM=99;
			break;
		default:
			printf("请作出正确的选择！\n");
			menu1();
	}
}
void initback(int arr[ROW][COL])
{
	int seedROW,seedCOL=0;
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			arr[ROW][COL]=0;
		}
	}
	for(int m=0;m<NUM;)
	{
		seedROW=rand()%(ROW-2)+1;
		seedCOL=rand()%(COL-2)+1;
		if(arr[seedROW][seedCOL]==0)
		{
			m++;
			arr[seedROW][seedCOL]=1;
		}
	}
	for(int n=0;n<10;n++)
	{
		arr[0][n]=1;
		arr[n][0]=1;
		arr[10][n]=1;
		arr[n][10]=1;
	}
}

void game()
{
	SNUM=ROW*COL-2*ROW-2*COL+4-NUM;
	int backBoard[ROW][COL];
	srand((unsigned int)time(NULL));
	initback(backBoard);
	char frontBoard[ROW][COL];
	init(frontBoard);
	flag = NUM;
	refresh(frontBoard);
	while(1)
	{
		int e=0;
		e=round(backBoard[ROW][COL],frontBoard[ROW][COL]);
		if(e==1)
			printf("恭喜你扫雷成功！\n");
			break;
		if(e==0)
			printf("很遗憾你踩到地雷了！\n");
			break;

	}

}





void menu()
{
	
        int n=0;
        printf("*********************************\n");
        printf("**********1.game 2.exit**********\n");
        printf("*********************************\n");
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

