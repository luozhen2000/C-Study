#include<stdio.h>

int main()
{
	/*
	char a = 3;
	//3---00000000000000000000000000000011
	//a---00000011
	char b = 127;
	//127---00000000000000000000000001111111
	//b---01111111
	
	//a+b
	//00000000000000000000000000000011
	//00000000000000000000000001111111
	//00000000000000000000000010000010
	//10000010 ---c
	//通过%d转化为int类型 正数补充0 负数补充1 整形提升
	//11111111111111111111111110000010 补码
	//11111111111111111111111110000001 反码
	//10000000000000000000000001111110 原码
	//所以c转化为int类型后输出为-126
	char c = a+b;
	printf("%d\n",c);

	*/
	/*
	char i = 0xb6;
	//0xb6---10110110
	//i整型提升后为11111111111111111111111110110110--- -74
	short j = 0xb600;
	//0xb600---1011011000000000
	//j整型提升后为11111111111111111011011000000000
	int k = 0xb6000000;
	//0xb6000000---10110110000000000000000000000000
	//k不用提升所以相等
	if (i == 0xb6)
		printf("i\n");
	if (i == 0xffffffb6)
		printf("i是-74(0xffffffb6)\n");
	if (j == 0xffffb600)
		printf("j\n");
	if (k == 0xb6000000)
		printf("k\n");
	*/

	char c =1;
	printf("%lu\n",sizeof(c));
	printf("%lu\n",sizeof(+c));
	printf("%lu\n",sizeof(!c));
	return 0;
}
