#include <stdio.h>
int main()
{
	int x=1,y=2,z=3;
	int *p,*q,*r;
	p=&x;
	q=&y;
	r=&z;
	printf("value of x is : %d\n",x);
	printf("value of y is : %d\n",y);
	printf("value of z is : %d\n",z);
	printf("value of p is : %d\n",p);
	printf("value of q is : %d\n",q);
	printf("value of r is : %d\n",r);
	printf("value of *p is : %d\n",*p);
	printf("value of *q is : %d\n",*q);
	printf("value of *r is : %d\n",*r);
	
	printf("Swapping pointers.\n");
	int *temp=r;
	r=p;
	p=q;
	q=temp;
	printf("value of x is : %d\n",x);
	printf("value of y is : %d\n",y);
	printf("value of z is : %d\n",z);
	printf("value of p is : %d\n",p);
	printf("value of q is : %d\n",q);
	printf("value of r is : %d\n",r);
	printf("value of *p is : %d\n",*p);
	printf("value of *q is : %d\n",*q);
	printf("value of *r is : %d\n",*r);
	
}