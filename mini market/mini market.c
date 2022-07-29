#include <stdio.h>
int main (void)
{
	int sales=0,quantity=0,part,chose;
	char flag=NULL;
	printf("please Enter shoping list:");
	while(flag=='n');
	{
		printf("to get partment just Enter it number:1-bakery\n2-Dairy products\n3-vegetables\n4-fruits");
		scanf("%d",&part);
		switch(part)
		{
			case 1 :
			printf("to get product enter it num:1-");
			break;
			case 2 :
			break;
			case 3 :
			break;
			case 4 :
			printf("to get product enter it num{1-apple: 5\n2-banana: 4\n3-orange: 3}\n num: ");
			scanf("%d",&chose);
			printf("quantity: ");
			scanf("%d",&quantity);
			switch(chose)
			{
				case 1 : sales+=(5*quantity); break;
				case 2 : sales+=(4*quantity); break;
				case 3 : sales+=(3*quantity); break;
				default: printf("you Enter unvalide num!!!! please try agine");
			}
			
			break;
		}
		
		
	}
	
	
	return 0;
}