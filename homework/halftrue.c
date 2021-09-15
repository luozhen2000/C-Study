#include <stdio.h>



//A:b第2,a第3
//B:b第2,e第4
//C:c第1,d第2
//D:c第5,d第3
//E:e第4,a第1
//五个人都只说了一半真话
int main()
{
	int a,b,c,d,e=1;
	for(a=1;a<6;a++)
	{
		for(b=1;b<6;b++)
		{
			for(c=1;c<6;c++)
			{
				for(d=1;d<6;d++)
				{
					for(e=1;e<6;e++)
					{
						if(((b==2)+(a==3)==1) &&
						  ((b==2)+(e==4)==1) &&
						  ((c==1)+(d==2)==1) &&
						  ((c==5)+(d==3)==1) &&
						  ((e==4)+(a==1)==1) &&
						  (a*b*c*d*e==120))
						  {
							  printf("a=%d b=%d c=%d d=%d e=%d\n",a,b,c,d,e);
						  }
					}
				}
			}
		}
	}
	return 0;
}

