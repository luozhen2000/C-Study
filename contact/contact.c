#include<stdio.h>
#include"contact.h"


	//printf("%-10s \t%-5s \t%-20s \t%-15s \t%-15s \t%-5s\n","姓名","性别","住址","QQ","电话","年龄");


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
	con->size++;

}





	
