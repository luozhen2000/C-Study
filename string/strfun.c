#include <stdio.h>
#include <string.h>
#include <assert.h>
//strncpy,strncat
char* my_strcpy(char* dest,const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	while(*dest++=*src++);
	return ret;
}



//const char*防止a[]被改变
int my_strlen(const char* str)
{
	assert(str!=NULL);
	if(*str++)
	{
		return 1+my_strlen(str);
	}
	return 0;
}
char* my_strcat(char* str1,const char* str2)
{
	assert(str1&&str2);
	int len=strlen(str1);
	char* ret=str1;
	while(*((str1++)+len)=*str2++);
	return ret;
}
//strcmp比的是字母大小，a~z
//大则返回正，小则返回负，相同则0
int my_strcmp(const char* str1,const char* str2)
{
	assert(str1&&str2);
	while(*str1&&*str2)
	{
		if((*str1)>*(str2))
			return 1;
		else if(*(str1)<*(str2))
			return -1;
		str1++;
		str2++;
	}
	return 0;
}


const char* my_strstr(const char* p1,const char* p2)
{
	assert(p1&&p2);
	//p2指向空字符串
	if(*p2=='\0')
		return p1;
	for(int i=0;i<strlen(p1);i++)
	{
		if(*(p1+i)==*p2)
		{
			for(int j=1;j<strlen(p2);j++)
			{
				if(*(p1+i+j)!=*(p2+j))
					break;
				if(j==strlen(p2)-1)
					return p1+i;
			}
		}
	}
	return NULL;
}




int main()
{
	char a[30]="abcdefghsadjashkj";//17
	printf("%d\n",my_strlen(a));
	char b[]="ttttt";
	//char *p="asd";//错误，因为此时为常量，会导致出错
	printf("%s\n",my_strcpy(a,b));
	printf("%s\n",my_strcat(a,b));
	//const char* 防止常量字符串被修改。
	const char* p1="dbc";
	const char* p2="abc";
	printf("%d\n",my_strcmp(p1,p2));

	const char* pa="13";
	const char* pb="werqweabcdas";
	const char* ret = my_strstr(pb,pa);
	if(ret==NULL)
		printf("找不到\n");
	else
		printf("%s\n",ret);//abcdas返回值是找到字符串的第一个字符的指针。

	//char* strtok(char* str,const char* sep);
	//将sep作为分隔符，
	char* str1="192.168.10.1";
	char* sep="...";
	printf("%s\n",strtok(str1,sep));




	return 0;
}
