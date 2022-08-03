#include <stdio.h>
void Add();
void Subtract();
void Multiply();
void Divide();
void And();
void Or();
void Not();
void Xor();
void reminder();
void Increment();
void Decrement();

int main()
{
	int ID,x,y;
	printf("please Enter ID opreation: ");
	scanf("%d",&ID);
	switch(ID)
	{
		case 1: Add(); break;
		case 2: Subtract(); break;
		case 3: Multiply(); break;
		case 4: Divide(); break;
		case 5: And(); break;
		case 6: Or(); break;
		case 7: Not(); break;
		case 8: Xor();break;
		case 9: reminder(); break;
		case 10: Increment(); break;
		case 11: Decrement(); break;
	}
}

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