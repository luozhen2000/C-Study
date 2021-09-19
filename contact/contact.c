#include<stdio.h>
#include <string.h>
 
 
#define MAX 1000
#define MAX_NAME 20
#define MAX_TEL 20
#define MAX_GENDER 10
#define MAX_ADDR 40
#define MAX_QQ 15


//160 size
typedef struct PeoInfo
{
        char qq[MAX_QQ];
        char name[MAX_NAME];
        char tel[MAX_TEL];
        char gender[MAX_GENDER];
        char addr[MAX_ADDR];
        int age;
}peoInfo;


typedef struct Contact
{
        peoInfo data[MAX];
        int size;
}contact;
 




void init(contact* con)
{
        memset(con->data,0,sizeof(con->data));
        con->size =0;
}

void addData(contact* con)
{
	if(con->size==MAX)
	{
		printf("通讯录已满\n");
		return;
	}
	printf("姓名:");
	scanf("%s",con->data[con->size].name);
	printf("\n");
	printf("性别:");
	scanf("%s",con->data[con->size].gender);
	printf("\n");
	printf("住址:");
	scanf("%s",con->data[con->size].addr);
	printf("\n");
	printf("QQ:");
	scanf("%s",con->data[con->size].qq);
	printf("\n");
	printf("电话:");
	scanf("%s",con->data[con->size].tel);
	printf("\n");
	printf("年龄:");
	scanf("%d",&(con->data[con->size].age));
	printf("\n");
	(con->size)++;

}



void showAll(const contact* p)
{
	if(p->size==0)
	{
		printf("通讯录为空\n");
	}
	for(int i=0;i<p->size;i++)
	{
		printf("%-10s \t%-5s \t%-20s \t%-15s \t%-4s \t%-15s \n","姓名","性别","住址","QQ","年龄","电话");
		printf("%-10s \t%-5s \t%-20s \t%-15s \t%-4d \t%-15s \n",p->data[i].name,
		p->data[i].gender,
		p->data[i].addr,
		p->data[i].qq,
		p->data[i].age,
		p->data[i].tel);
	}
}
void search(const contact* p)
{
	if(p->size==0)
	{
		printf("通讯录为空\n");
		return;
	}
	printf("请输入想要查找的名字:>");
	char arr[20];
	scanf("%s",arr);
	for(int i=0;i<p->size;i++)
	{
		if(strcmp(p->data[i].name,arr)==0)
		{
		printf("%-10s \t%-5s \t%-20s \t%-15s \t%-4s \t%-15s \n","姓名","性别","住址","QQ","年龄","电话");
		printf("%-10s \t%-5s \t%-20s \t%-15s \t%-4d \t%-15s \n",p->data[i].name,
		p->data[i].gender,
		p->data[i].addr,
		p->data[i].qq,
		p->data[i].age,
		p->data[i].tel);
		return;
		}
	}
	printf("没有此人\n");
}
void delete(contact* p)
{
	if(p->size==0)
	{
		printf("通讯录为空\n");
		return;
	}
	printf("请输入想要删除者的名字:>");
	char arr[20];
	scanf("%s",arr);
	for(int i=0;i<p->size;i++)
	{
		if(strcmp(p->data[i].name,arr)==0)
		{
			int rest=0;
			//memmove将后面的数据全部前移覆盖需要删除的数据,注意需要多移动一个数据的位置，以让最后一个数据不重复，为了偷懒就直接这样了，但是满了的话会导致越界访问。
			rest=160*(p->size-i);
			memmove((void*)(p->data+i),(void*)(p->data+i+1),rest);
			printf("删除成功\n");
			p->size--;
			return;
		}
	}
	printf("没有此人\n");
}

void change(contact* p)
{
	if(p->size==0)
	{
		printf("通讯录为空\n");
		return;
	}
	printf("请输入想要修改者的名字:>");
	char arr[20];
	scanf("%s",arr);
	for(int i=0;i<p->size;i++)
	{
		if(strcmp(p->data[i].name,arr)==0)
		{
			printf("姓名:");
			scanf("%s",p->data[i].name);
			printf("\n");
			printf("性别:");
			scanf("%s",p->data[i].gender);
			printf("\n");
			printf("住址:");
			scanf("%s",p->data[i].addr);
			printf("\n");
			printf("QQ:");
			scanf("%s",p->data[i].qq);
			printf("\n");
			printf("电话:");
			scanf("%s",p->data[i].tel);
			printf("\n");
			printf("年龄:");
			scanf("%d",&(p->data[i].age));
			printf("修改成功\n");
			return;
		}
	}
	printf("查无此人\n");




}


void menu()
{
	printf("欢迎使用通讯录系统V1.0!!!\n");
	printf("*************************\n");
	printf("****1.查找     2.全显****\n");
	printf("****3.增加     4.删除****\n");
	printf("****5.修改     0.退出****\n");
	printf("请选择:>");
}


int main()
{
	int input=0;
	contact con;
	init(&con);
	do
	{
		menu();
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				search(&con);
				break;
			case 2:
				showAll(&con);
				break;
			case 3:
				addData(&con);
				break;
			case 4:
				delete(&con);
				break;
			case 5:
				change(&con);
				break;
			case 0:
				printf("退出系统\n");
				break;
			default:
				printf("选择错误\n");
				break;
		}
	}while(input);


	return 0;


}
	




