#include<stdio.h>


int my_strlen(char* str);
int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int i =0;
	int sz= sizeof(arr)/sizeof(arr[0]);
	int* p=arr;
	for(i=0;i<sz;i++)
	{
		printf("%d ",*p);
		p++;
	}
	printf("\n");
	printf("%d\n",&arr[9]-&arr[0]);//指针相减结果时元素个数
	char arr1[]="bit";
	int len = my_strlen(arr1);
	printf("%d\n",len);


	return 0;
}


int my_strlen(char* str)
{
	char* start = str;
	char* end = str;
	while(*end!='\0')
	{
		end++;
	}
	
	return end - start;
}

