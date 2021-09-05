#include<stdio.h>


void bubble_sort(int arr[],int sz)
{
	int i = 0;
	int j = 0;
	for(i;i<sz-1;i++)
	{
		for(j =0;j<sz-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int tmp=arr[j];
				arr[j] = arr[j+1];
				arr[j+1]= tmp;
			}
		}
	}
}

int main()
{
	int arr[]={9,10,7,3,2,1};
	int sz=sizeof(arr)/sizeof(arr[0]);
	printf("排列后的数组为:\n");
	bubble_sort(arr,sz);
	for(int i = 0;i<sz;i++)
		printf("%d ",arr[i]);

	return 0;
}
