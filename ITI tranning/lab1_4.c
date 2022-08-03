#include <stdio.h>
int main()
{
	int x=5;
	printf("brfore change : %d\n",x);
	int *ptr=&x;
	*ptr =20;
	printf("after change : %d",x);
}