#include <stdio.h>
#include <string.h>
#include <assert.h>
typedef struct
{
	char name[20];
	int age;
}S;

void* my_memcpy(void* dest,const void* src,size_t num)
{
	void* ret=dest;
	assert(dest&&src);
	int i =0;
	while(i++<num)
		*(char*)dest++=*(char*)src++;
	return ret;
}
void* my_memmove(void* dest,const void* src,size_t count)
{
	assert(dest&&src);
	void* ret=dest;
	if(dest<src)
	{
		int i =0;
		while(i++<count)
		{
			*(char*)dest=*(char*)src;
			dest++;
			src++;
		}
		return ret;
	}
	if(dest>=src)
	{
		int j=0;
		while(j++<count)
		{
			*((char*)(dest+count-1))=*((char*)(src+count-1));
			dest--;
			src--;
		}
		return ret;
	}
}
		



int main()
{
	int arr1[] = {1,2,3,4,5};
	int arr2[5]={0};
	S arr3[]={{"张三",20},{"李四",23}};
	S arr4[3]={0};
	//拷贝内存
	my_memcpy(arr2,arr1,sizeof(arr1));
	my_memcpy(arr4,arr3,sizeof(arr3));
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int i=0;
	printf("%d\n",arr2[4]);
	printf("%d\n",arr4[1].age);
	printf("%d\n",arr4->age);
	my_memmove(arr+2,arr,20);
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	//memmov解决内存重叠的拷贝情况




	return 0;
}
