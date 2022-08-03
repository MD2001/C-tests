#include <stdio.h>
void psum(int *x,int *y,int *sum,int *sbtract);
int main()
{
	int num1,num2,sum,sbtract;
	printf("Enter num1: ");
	scanf("%d",&num1);
	printf("Enter num2: ");
	scanf("%d",&num2);
	psum(&num1,&num2,&sum,&sbtract);
	printf("the sum is: %d\n",sum);
	printf("the sbtract is: %d",sbtract);
	
}
void psum(int *x,int *y,int *sum,int *sbtract )
{
	 *sum=(*x+*y);
	 *sbtract=(*x-*y);
}
