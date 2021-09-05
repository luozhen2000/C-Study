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
int player_round(char arrf[ROWS][COLS],char arrb[ROWS][COLS],int* flag)
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
                        if(((row<1)||(row>ROW+1))
                        ||((col<1)||(col>COL+1))
			||(arrf[row][col]=='F'))
                        {
                                printf("请选择正确的位置\n");
                                return player_round(arrf,arrb,&(*flag));
                                break;
                        }

                        if(arrb[row][col]=='1')
                        {
				arrf[row][col]='*';
                                return 0;
                        }
                        else
                        {
                                check(arrf,arrb,row,col);
                                if(isWin(arrb,arrf)==1)
                                {
                                        return 1;
                                }
                        }
			return 3;
                        break;
                case 2:
			if(*flag==0)
			{
				printf("你的旗子数已用完！请取消插旗！");
                                return player_round(arrf,arrb,&(*flag));
				break;
			}
                        printf("请选择你下一步行动的位置(行，列):");
			scanf("%d",&row);
                        scanf("%d",&col);
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

                                                                     
void game()
{
	char arrf[ROWS][COLS];
	char arrb[ROWS][COLS];
	initb(arrb);
	initf(arrf);
	int flag =NUM;
        fresh(arrf,flag);
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
