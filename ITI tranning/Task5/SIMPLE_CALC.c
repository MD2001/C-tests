#include <stdio.h>

void Add()
{
	int x,y;
	printf("please Enter two operand \n");
	printf("num1: ");
	scanf("%d",&x);
	printf("num2: ");
	scanf("%d",&y);
	printf("the value is %d + %d = %d  ",x,y,(x+y));
}

void Subtract()
{
	int x,y;
	printf("please Enter two operand \n");
	printf("num1: ");
	scanf("%d",&x);
	printf("num2: ");
	scanf("%d",&y);
	printf("the value is %d - %d = %d  ",x,y,(x-y));
}
void Multiply()
{
	int x,y;
	printf("please Enter two operand\n");
	printf("num1: ");
	scanf("%d",&x);
	printf("num2: ");
	scanf("%d",&y);
	printf("the value is %d * %d = %d  ",x,y,(x*y));
}
void Divide()
{
	int x,y;
	printf("please Enter two operand \n");
	printf("num1: ");
	scanf("%d",&x);
	printf("num2: ");
	scanf("%d",&y);
	printf("the value is %d / %d = %d  ",x,y,(x/y));
}
void And()
{
	int x,y;
	printf("please Enter two operand \n");
	printf("num1: ");
	scanf("%d",&x);
	printf("num2: ");
	scanf("%d",&y);
	printf("the value is %d & %d = %d  ",x,y,(x&y));
}
void Or()
{
	int x,y;
	printf("please Enter two operand\n");
	printf("num1: ");
	scanf("%d",&x);
	printf("num2: ");
	scanf("%d",&y);
	printf("the value is %d | %d = %d  ",x,y,(x|y));
}
void Not()
{
	int x;
	printf("please Enter one operand \n");
	printf("num1: ");
	scanf("%d",&x);
	printf("the value is ~%d = %d  ",x,~x);
}
void Xor()
{
	int x,y;
	printf("please Enter two operand \n");
	printf("num1: ");
	scanf("%d",&x);
	printf("num2: ");
	scanf("%d",&y);
	printf("the value is %d ^ %d = %d  ",x,y,(x^y));
}
void reminder()
{
	int x,y;
	printf("please Enter two operand \n");
	printf("num1: ");
	scanf("%d",&x);
	printf("num2: ");
	scanf("%d",&y);
	printf("the value is %d % %d = %d  ",x,y,(x%y));
}
void Increment()
{
	int x;
	printf("please Enter one operand\n");
	printf("num1: ");
	scanf("%d",&x);
	printf("the value is ++%d = ",x);
	printf("%d ",++x);
}
void Decrement()
{
	int x;
	printf("please Enter one operand \n");
	printf("num1: ");
	scanf("%d",&x);
	printf("the value is --%d = ",x);
	printf("%d ",--x);
}