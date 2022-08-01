#include <stdio.h>

void main(void)

{
	int x=0;
	printf("please enter the answer of 3 * 4 = ");
	scanf("%d",&x);

	while(x!=12)
	{
		printf("not correct ,please tey agine: ");
		scanf("%d",&x);
		
	}
	printf("thank you!!");
}
