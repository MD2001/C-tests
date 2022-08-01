#include <stdio.h>

void main(void)

{
	int num;
	printf("Enter num: ");
	scanf("%d",&num);
	for(int i=1;i<=num;i++)
	{
		for(int y=1;y<i+1;y++)
		{
			printf("%d",y);
		}
		printf("\n");
	}
	
}
