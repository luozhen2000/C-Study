#include <stdio.h>

//位段 二进制位
//位段按照int或者char来进行空间开辟
//所以下面的位段一共47位，为int类型，所以一个int32，所以需要两个int
struct S
{
	int a:2;
	int b:5;
	int c:10;
	int d:30;
};
int main()
{
	struct S s;
	printf("%d\n",sizeof(s));//8





	return 0;
}
