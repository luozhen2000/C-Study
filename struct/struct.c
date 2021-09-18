#include <stdio.h>
#include <stddef.h>



//结构体的定义
//定义的时候让小的变量尽量定义在一起，有助于节约空间
struct stu
{
	int age;
	char name[10];
};

typedef struct stu2
{
	int age;
	char name[10];
}stu2;

struct
{
	int age;
	char name[10];
}stu3;

struct Node
{
	int a;
	struct Node* next;
};

//结构体 第一个变量放在0偏移量
//其他成员放在对齐数的倍数上    对齐数：元素取变量大小与编译器默认对齐数之中的较小值
//结构体总大小为最大对齐数的整数倍 gcc没有默认对齐数
struct S1
{
	char c1;
	int a;
	char c2;
};
struct S2
{
	char c1;
	char c2;
	int a;
};
struct S3
{
	char c1;
	struct S2 s;
	double d;
};
int main()
{
	struct S1 s1={0};
	printf("%d\n",sizeof(s1));//12
	struct S2 s2={0};
	printf("%d\n",sizeof(s2));//8
	struct S3 s3={0};
	printf("%d\n",sizeof(s3));//24
	//offsetof 宏 计算结构体中成员的偏移量
	printf("%d\n",offsetof(struct S3,s));//





	return 0;
}
	
