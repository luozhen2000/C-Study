#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define WHITE printf("\033[37m");
#define RED printf("\033[31m");
#define ROW 9
#define COL 9
#define NUM 10
#define ROWS ROW+2
#define COLS COL+2
#define SNUM ROW*COL-NUM
//判断是否获胜的函数，当旗帜标出所有地雷获胜，或者是所有没有地雷的格子都已显示
int isWin(char arrb[ROWS][COLS],char arrf[ROWS][COLS])
{
        int count=0;
        for(int i=0;i<ROWS;i++)
        {
                for(int j=0;j<COLS;j++)
                {
                        if(arrb[i][j]=='0')
                        {
                                if((arrf[i][j]!=' ')&&(arrf[i][j]!='F'))
                                        count++;
                        }
                }
        }
        if(count==SNUM)
                return 1;
	count = 0;
	for(int m=1;m<ROW+1;m++)
	{
		for(int n=1;n<COL+1;n++)
		{
			if((arrb[m][n]=='1')&&(arrf[m][n]=='F'))
				count++;
		}
	}
        if(count==NUM)
                return 1;
        return 0;
}
//检查此格周围的地雷数并返回
int checkMine(int row,int col,char arrb[ROWS][COLS])
{
        int count=0;
        for(int i=row-1;i<row+2;i++)
        {
                for(int j=col-1;j<col+2;j++)
                {
                        if(arrb[i][j]=='1')
                                count++;
                }
        }
        return count;
}
//初始化arrb的函数，即生成地雷的位置，最外面一圈为'F'
void initb(char arrb[ROWS][COLS])
{
	int count=0;
	srand((unsigned)time(NULL));
	int seedROW,seedCOL=0;
        for(int i=0;i<ROWS;i++)
        {
                for(int j=0;j<COLS;j++)
                {
                        arrb[i][j]='0';
                }
        }
	while(1)
        {
                seedROW=rand()%ROW+1;
                seedCOL=rand()%COL+1;
                if(arrb[seedROW][seedCOL]=='0')
                {
			count++;
                        arrb[seedROW][seedCOL]='1';
                }
		if(count==NUM)
			break;
        }
        for(int n=0;n<10;n++)
        {
                arrb[0][n]='F';
                arrb[n][0]='F';
                arrb[10][n]='F';
                arrb[n][10]='F';
        }
}
//初始化arrf的函数，将arrf最外面一圈为'F',中间为' '
void initf(char arrf[ROWS][COLS])
{
        for(int i=0;i<ROWS;i++)
        {
                for(int j=0;j<COLS;j++)
                {
                        arrf[i][j]=' ';
                }
        }
        for(int x=0;x<10;x++)
        {
                arrf[0][x]='F';
                arrf[x][0]='F';
                arrf[10][x]='F';
                arrf[x][10]='F';
        }

}
//刷新棋盘，显示flag数量
void fresh(char arrf[ROWS][COLS],int flag)
{
	printf("Flag:%d\n",flag);
	int y=1;
        for(int i=1;i<ROW+1;i++)
        {
		if(i==1)
		{
			printf(" ");
			int n;
			for(n=1;n<COL+1;n++)
			{
				printf("  %d ",n);
			}
		}
			printf("\n");
			printf("  ");
			for(int m=0;m<COL;m++)
			{
                        	printf("--- ");
			}
			printf("\n");
			printf("%d|",y);
			y++;
                for(int j=1;j<COL+1;j++)
                {
			if((arrf[i][j]=='F')||(arrf[i][j]=='*'))
			{
				RED
			}
                        printf(" %c ",arrf[i][j]);
			WHITE
			printf("|");
		}
		if(i==ROW)
		{
			printf("\n");
			printf("  ");
			for(int t=0;t<COL;t++)
			{
                        	printf("--- ");
			}
		}
        }
	printf("\n\n");

}
//check函数检测周围有多少地雷，如果没有则显示为0并且扩散检测上下左右是否也为0
int check(char arrf[ROWS][COLS],char arrb[ROWS][COLS],int row,int col)
{

        if(arrf[row][col]==' ')
        {
                int mine=checkMine(row,col,arrb);
                if(mine==0)
                {
                        arrf[row][col]='0';
			int i =row-1;
			int j =col;
                        check(arrf,arrb,i,j);
                 	i++;
			j--;
			check(arrf,arrb,i,j);
			j+=2;
			check(arrf,arrb,i,j);
			i++;
			j--;
			check(arrf,arrb,i,j);
                }
                else
                        //int类型+48也就是char类型的'0'
                        arrf[row][col]=mine+48;
        }
        else
                return 0;
}
//玩家行动函数，三种行动，扫雷，插旗，拔旗
int player_round(char arrf[ROWS][COLS],char arrb[ROWS][COLS],int* flag)
{
        int input,row,col =0;
        printf("请选择你的下一步行动\n");
        printf("1.go 2.setFlag 3.cancelFlag\n");
        printf(":>");
        scanf("%d",&input);
        switch(input)
        {
		//扫雷时，如果选择位置超出范围或者已经插旗则提示并且重新进行开始回合
                case 1:
                        printf("请选择你下一步行动的位置(行，列):");
                        scanf("%d",&row);
                        scanf("%d",&col);
                        if(((row<1)||(row>ROW+1))
                        ||((col<1)||(col>COL+1))
			||(arrf[row][col]=='F'))
                        {
                                printf("请选择正确的位置\n");
                                return player_round(arrf,arrb,&(*flag));
                                break;
                        }
			//如果踩到雷，则在此格显示*并且返回0表示游戏失败
                        if(arrb[row][col]=='1')
                        {
				arrf[row][col]='*';
                                return 0;
                        }
                        else
                        {
				//行动后检测周围有无地雷，检测完毕后判断是否获胜
				//获胜则返回1
                                check(arrf,arrb,row,col);
                                if(isWin(arrb,arrf)==1)
                                {
                                        return 1;
                                }
                        }
			return 3;
                        break;
                case 2:
			//插旗时首先判断是否还有旗
			if(*flag==0)
			{
				printf("你的旗子数已用完！请取消插旗！");
                                return player_round(arrf,arrb,&(*flag));
				break;
			}
                        printf("请选择你下一步行动的位置(行，列):");
			scanf("%d",&row);
                        scanf("%d",&col);
			//然后判断是否超出范围或者此位置为已经显示的位置
                        if(((row<1)||(row>ROW+1))
                        ||((col<1)||(col>COL+1))
			||(arrf[row][col]!=' '))
                        {
                                printf("请选择正确的位置\n");
                                return player_round(arrf,arrb,&(*flag));
                                break;
                        }
                        arrf[row][col]='F';
                        *flag-=1;
                        if(isWin(arrb,arrf)==1)
                        {
                                return 1;
                        }
			return 3;
                        break;
                case 3:
                        printf("请选择你下一步行动的位置(行，列):");
                        scanf("%d",&row);
                        scanf("%d",&col);
                        if(((row<1)||(row>ROW+1))
			||((col<1)||(col>COL+1))
			||(arrf[row][col]!='F'))
                        {
                                printf("请选择正确的位置\n");
                                return player_round(arrf,arrb,&(*flag));
                                break;
                        }
                        else
                        {
                                arrf[row][col]=' ';
                                *flag+=1;
                        }
			return 3;
                        break;
                default:
                        printf("请选择正确的行动\n");
                        return player_round(arrf,arrb,&(*flag));
                        break;
        }
}

//游戏主体                                                                     
void game()
{
	//创建arrf前景版，arrb背景板
	char arrf[ROWS][COLS];
	char arrb[ROWS][COLS];
	//初始化arrf与arrb
	initb(arrb);
	initf(arrf);
	int flag =NUM;
	//显示初始棋盘
        fresh(arrf,flag);
	//开始游戏，返回1则胜利，返回0则失败
	//胜利或失败后展示地雷位置
        while(1)
        {
                int e=3;
                e=player_round(arrf,arrb,&flag);
                if(e==1)
		{
			fresh(arrb,flag);
			fresh(arrf,flag);
                        printf("恭喜你扫雷成功！\n");
                        break;
		}
                if(e==0)
		{
			fresh(arrb,flag);
			fresh(arrf,flag);
                        printf("很遗憾你踩到地雷了！\n");
                        break;
		}
		fresh(arrf,flag);

        }

}
//游戏选择菜单
int menu()
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
			return 1;
                        break;
                case 2:
                        printf("退出游戏\n");
			return 2;
                        break;
                default:
                        printf("请输入正确的选择！\n");
                        return menu();
                        break;
        }
}

int main()
{
	int end=menu();
	if(end==1)
		game();
	if(end==2)
		return 0;
	return 0;
}
