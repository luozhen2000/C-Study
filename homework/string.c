#include <stdio.h>
#include <string.h>



void reverse(char* left,char* right)
{
	while(left<=right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		right--;
		left++;
	}
}



//通过逆序来达成左旋的效果，即将一个字符串左旋k位，例如abcdef左旋3位，则是fedabc
void left_move(char* str,int k)
{
	int len=strlen(str);
	reverse(str,str+k-1);
	reverse(str+k,str+len-1);
	reverse(str,str+len-1);
}

int is_left_move(char* str1 , char* str2)
{
	if(strlen(str1)!=strlen(str2))
		return 0;
	int len=strlen(str1);
	int i=0;
	for(i=0;i<len;i++)
	{
		left_move(str1,1);
		//strcmp返回0则表示两字符串相同
		int ret=strcmp(str1,str2);
		if(ret==0)
			return 1;
	}
	return 0;
}
int is_left_move2(char* str1,char* str2)
{
	if(strlen(str1)!=strlen(str2))
		return 0;
	int len=strlen(str1);
	
	//strcat(str1,str2)不能追加自身，strncat(str1,str2,n)可以
	//追加后查看追加后的str1的子串是否含有str2即可知道str2是否可由str1旋转所得
	strncat(str1,str1,len);

	//strstr(char*,char*)函数查看第二个字符串是否为第一个字符串的子串，如果是则返回第二字符串首字符在第一字符串中的指针
	char* ret=strstr(str1,str2);
	if(ret==NULL)
		return 0;
	else
		return 1;
}




int main()
{
	char a[30]="abcdef";
	char b[]="efabcd";
	int ret = is_left_move(a,b);
	printf("%s\n%s\n",a,b);
	if(ret==1)
		printf("yes\n");
	else
		printf("no\n");





	return 0;
}
