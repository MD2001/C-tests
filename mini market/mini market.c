#include <stdio.h>
int main (void)
{
	int pnum;
	int products[12]={0};
	int prices[12]={5,3,1,5,5,3,1,8,6,4,7,2};
	char names[20][12]={"","","","","","","","","","apple","banana","orange"};
	double sales=0.0;
	int quantity=0;
	int	part,chose;
	char flag='c';
	printf("==============welcome to my Market================\n");
	while(flag != 'n')
	{
		printf("to get partment just Enter it number:\n");
		printf("1-bakery\n2-Dairy products\n3-vegetables\n4-fruits\n");
		printf("num: ");
		scanf("%d",&part);
		switch(part)
		{
			case 1 :
			break;
			case 2 :
			break;
			case 3:
			break;
			case 4 :
			printf("================fruits part================\n");
			printf("to get product enter it num: {1-apple:%d$ ,2-banana:%d$ ,3-orange:%d$ }\nnum: ",
			prices[9],prices[10],prices[11]);
			scanf("%d",&chose);
			printf("quantity: ");
			scanf("%d",&quantity);
			
			switch(chose)
			{
				case 1 : products[9]+=quantity; break;
				case 2 : products[10]+=quantity; break;
				case 3 : products[11]+=quantity; break;
				default: printf("you Enter unvalide num!!!! please try agine\n"); break;
			}
			
			break;
			default:printf("you Enter unvalide num!!!! please try agine\n");break;
		}
		
		printf("==================your fee=======================\n");
		sales=0;
		pnum=0;
		for(int i=0;i<12;i++)
		{ 
			if(products[i]!=0)
			{ pnum++;
				sales+=prices[i]*products[i];
				printf("%s : %d\n",names[i],products[i]);
			}				
		}
		printf("your proudct num is : %d\n",pnum);
		printf("your cost is : %0.2f$\n",sales);
		if(pnum>=5)
		{
			sales*=0.2;
		}
		printf("================================================\n");
		printf("for end selling please Enter n else Enter any key\n");
		scanf(" %c",&flag);
		
		
	}
	if(pnum<2)
	{
		printf("you must have more than 1 item to get order");
	}
	else
	{
		
	}
	
	
	return 0;
}
