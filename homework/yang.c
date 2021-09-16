#include<stdio.h>


//杨氏矩阵，数字从左往右，从上往下递增，从中查找一个数，时间复杂度小鱼O(n)
//通过对比右上角或者左下角的数可以做到
int findnum(int arr[3][3],int k,int row,int col)
{
	int x=0;
	int y=col-1;
	while(x<=row-1 && y>-1)
	{
		if(arr[x][y]>k)
			y--;
		else if(arr[x][y]<k)
			x++;
		else
			return 1;
	}
	return 0;
}




int main()
{
	int arr[3][3]={{1,2,3},{3,4,5},{6,7,8}};
	int k=3;
	int ret = findnum(arr,k,3,3);
	if(ret==1)
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}
	

