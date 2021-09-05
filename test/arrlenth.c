#include<stdio.h>
#include<string.h>
int main()
{
	char arr[]="Ashen&&";
	printf("%s\n",arr);
	printf("%ld\n",strlen(arr));
	int length=sizeof(arr)/sizeof(arr[0]);
	printf("%d\n",length);
	return 0;
}
