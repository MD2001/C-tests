#include <stdio.h>
int max(int num1,int num2,int num3,int num4);
int min(int num1,int num2,int num3,int num4);
void main()
{
	int num1,num2,num3,num4;
	printf("Enter 4 num\n");
	printf("Enter num1: ");
	scanf("%d",&num1);
	printf("Enter num2: ");
	scanf("%d",&num2);
	printf("Enter num3: ");
	scanf("%d",&num3);
	printf("Enter num4: ");
	scanf("%d",&num4);
	printf("the max num is : %d\n",max( num1, num2, num3, num4));
	printf("the min num is : %d",min( num1, num2, num3, num4));
	
	
	
}
int max(int num1,int num2,int num3,int num4)
{
	int top=num1;
	if(top<num2) top=num2;
	if(top<num3) top=num3;
	if(top<num4) top=num4;
	return top;
}
int min(int num1,int num2,int num3,int num4)
{
	int low=num1;
	if(low>num2) low=num2;
	if(low>num3) low=num3;
	if(low>num4) low=num4;
	return low;
}