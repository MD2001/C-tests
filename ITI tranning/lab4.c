#include <stdio.h>

void main(void)

{
	int x=4;
	int y=7;
	printf(" %d | %d = %d\n",x,y,x|y);
	printf(" %d & %d = %d\n",x,y,x&y);
	printf(" %d ^ %d = %d\n",x,y,x^y);
	printf(" %d << 1 = %d\n",x,y,x<<1);
	printf(" %d >> 2 = %d\n",x,y,x>>2);
}