#include <stdio.h>

void main(void)
{
	int hight;
	printf("please Enter hight of pyramids: ");
	scanf("%d",&hight);
	
	for(int i=0 ;i<=hight;i++)
	{
		for(int space=0;space<10-i;space++)
			
			{
				printf(" ");
			}
			for(int stars=1;stars<2*i;stars++)
			{
				printf("*");
			}
			printf("\n");
	}
	
}
