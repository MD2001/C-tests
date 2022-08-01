#include <stdio.h>

void main(void)

{
	int num;
	printf("Enter your num: ");
	scanf("%d",&num);
	switch (num)
	{
		
		case 1234:  printf("hello ahmed");    break;
		case 3333:  printf("hello mohamed");  break;
		case 2222:  printf("hello yassr");    break;
		case 1111:  printf("hello omar");     break;
		case 4444:  printf("hello zead");     break;
		default :   printf("not found");      break;
	}

}
