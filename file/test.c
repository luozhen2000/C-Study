#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>



struct S
{
	int a;
	float score;
	char c1[100];
};
int main()
{
	//"r","w","a"
	//只读：打开一个已经存在的文件。只写：打开一个文件，如果没有则新建。追加：向文件尾追加，没有则报错
	//"rb","wb","ab"
	//二进制模式
	//"r+","w+","a+"
	//读写模式，w+和a+会建立新文件
	int a=10000;
	FILE* pf= fopen("test1.txt","w");
	if(pf==NULL)
	{
		//strerror头文件string.h
		printf("%s\n",strerror(errno));
		return 0;
	}
	//wb二进制写入
	//将文件的相关信息，如大小，类型等，保存在一个结构体中，结构体就是FILE，创建了一个文件指针变量
	//fwrite(&a,4,1,pf);
	//写 1 个 4 字节 的数据 &a 入 pf 中
	fputc('A',pf);
	fputc('s',pf);
	fputc('h',pf);
	fputc('e',pf);
	fputc('n',pf);
	fputc('&',pf);
	fputc('&',pf);
	fputc('\n',pf);
	fputs("hello\n",pf);
	char b[1024];
	char c[1024];
	fputs("world\n",pf);
	fclose(pf);
	pf=NULL;
	pf= fopen("test1.txt","r");
	if(pf==NULL)
	{
		//strerror头文件string.h
		printf("%s\n",strerror(errno));
		return 0;
	}
	printf("%c",fgetc(pf));
	printf("%c",fgetc(pf));
	printf("%c",fgetc(pf));
	printf("%c",fgetc(pf));
	printf("%c",fgetc(pf));
	printf("%c",fgetc(pf));
	printf("%c",fgetc(pf));
	printf("%c",fgetc(pf));
	//fgets会读入换行
	fgets(b,1024,pf);
	printf("%s",b);
	fgets(c,1024,pf);
	printf("%s",c);
	fclose(pf);
	pf=NULL;
	
	char buf[1024]={0};
	//标准输出，标准输入
	fgets(buf,1024,stdin);
	fputs(buf,stdout);
	//文件缓冲区
	//printf输出到标准输出的时候是行输出模式，所以遇到\n或者buffer满了之后才会输出。
	//while(1)
	//{
	//	sleep(1);
	//	printf("hehe");
	//}
	pf = fopen("test2.txt","w");
	struct S s={1,2.33,"Ash"};
	fprintf(pf,"%d %f %s",s.a,s.score,s.c1);

	fclose(pf);
	pf=NULL;


	pf = fopen("test2.txt","r");
	float score;
	char c1[100];
	fscanf(pf,"%d %f %s",&a,&score,c1);
	printf("%d %f %s",a,score,c1);
	fprintf(stdout,"%d %f %s",a,score,c1);
	fclose(pf);
	pf=NULL;

	



	return 0;



}
