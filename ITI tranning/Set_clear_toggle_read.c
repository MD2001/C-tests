#include <stdio.h>

void main(void)

{
	int x,bit,n,target;
	
	printf("Enter your data : ");
	scanf("%d",&x);
	printf("Enter your bit : ");
	scanf("%d",&bit);
	
	  printf("Enter your choice : {1-set , 2-clear,3-toggle ,4-read }");
	  scanf("%d",&target);
	  switch(target)
	  {
		  case 1 :
		   n=(x|(1<<bit));
		   break;
		   case 2 :
		   n=(x&(~(1<<bit)));
		   break;
		   case 3 :
		   n=(x^(1<<bit));
		   break;
		   case 4 :
		   n=(1&(x>>bit));
		   break;
	  }
	  printf("your target is : %d",n);
	 
	 
}