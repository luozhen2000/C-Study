#include<stdio.h>


int Add(int x,int y)
{
	return x+y;
}
int Sub(int x,int y)
{
	return x-y;
}
int Mul(int x,int y)
{
	return x*y;
}
int Div(int x,int y)
{
	return x/y;
}


int main()
{
	int a;
	int x,y=0;
	//p是一个函数指针数组 - 转移表
	int (*p[5])(int,int)={0,Add,Sub,Mul,Div};
	do
	{
		printf("请选择你的计算方式:>\n");
		printf("*********************\n");
		printf("**1.Add*******2.Sub**\n");
		printf("**3.Mul*******4.Div**\n");
		printf("*******0.exit********\n");
		scanf("%d",&a);
		if(a<=4 && a>0)
		{
			printf("请输入两个操作数:>");
			scanf("%d%d",&x,&y);
			printf("%d\n",p[a](x,y));
		}
		else if(a==0)
		{
			printf("退出\n");
		}
		else
		{
			printf("选择错误\n");
		}
	}while(a);
	
	//第一步：找到名字，也就是signal并查看与之相连最高优先度的符号
	//也就是signal(int,void(*)(int))，而这是一个函数，其参数类型为int和void(*)(int)
	//void(*)(int)是一个函数指针，指向一个参数为int，返回值为void的函数
	//第二步：查看剩下的部分，即是中间部分的内容，void(*)(int)即函数signal的返回值 
	void(*signal(int,void(*)(int)))(int);
	typedef void(*fun)(int);//将fun定义为void(*)(int)类型
	fun signal(int,fun);//等同于之前那行

	//(*(void(*)())0)();这行代码表示将0强制转换为void(*)()类型然后再解引用运行此函数




	return 0;
}








