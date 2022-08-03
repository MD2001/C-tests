#include <stdio.h>
void max(int x,int y);
int main()
{
	int num1,num2;
	printf("Enter num1 : ");
	scanf("%d",&num1);
	printf("Enter num2 : ");
	scanf("%d",&num2);
	max(num1,num2);
}
void max(int x,int y)
{
	if(x>y)
	{ 
		printf("max is %d",x);
	}
	else{
		printf("max is %d",y);
	}
}
