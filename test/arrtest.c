#include <stdio.h>
int main()
{
	int arr[3][4];
	int i=0;
	for(i;i<3;i++)
	{
		int j=0;
		for(j;j<4;j++)
		{
			printf("&arr[%d][%d] = %p\n",i,j,&arr[i][j]);
		}
	}	

	
	return 0;
	

}

