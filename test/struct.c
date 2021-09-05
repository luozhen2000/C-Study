#include<stdio.h>


struct Stu
{
	char name[10];
	int age;
	char id[20];
	char gender[10];
};

int main()
{
	struct Stu luozhen = {"Ashen&&",17,"1996","男"};
	struct Stu* pl = &luozhen;
	printf("%s\n",(*pl).name);
	printf("%s\n",pl->gender);
	return 0;
}
