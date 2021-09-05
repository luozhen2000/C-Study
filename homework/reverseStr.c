#include<stdio.h>
//倒置字符串
int left=0;
int right=0;

//使用指针来计算strlen
int strlen1(char* str)
{
	int count=0;
	while(*str !='\0')
	{
		count++;
		str++;
	}
	return count;
}
void reverseStr(char arr[],int sz)
{
	/*
	while(left<=right)
	{
		char c;
		c=arr[left];
		arr[left]=arr[right];
		arr[right]=c;
		left++;
		right--;
	}
	*/
	if(left<=right)
	{
		char c;
		c=arr[left];
		arr[left]=arr[right];
		arr[right]=c;
		left++;
		right--;
		reverseStr(arr,sz);
	}

}
void reverseStr1(char* str,int sz)
{
	static int i=0;
	char tmp;
	tmp=*(str+i);
	*(str+i)=*(str+sz-i-1);
	*(str+sz-i-1)=tmp;
	i++;
	if(i<=3)
	{
		reverseStr1(str,sz);
	}
}
        
int main()
{
	char arr[]="abcdefg";
	printf("%s\n",arr);
	int sz = strlen1(arr);
	right= sz-1;
	reverseStr1(arr,sz);
	printf("%s\n",arr);
	return 0;
}
