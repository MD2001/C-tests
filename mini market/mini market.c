#include <stdio.h>
int main (void)
{
	int pnum;
	int products[12]={0};
	int prices[12]={5,3,1,5,5,3,1,8,6,4,7,2};
	char names[20][12]={"cookies","cakes","cupcakes","milk","butter","cheese","Tomato","Garlic","Pumpkin","apple","banana","orange"};
	double sales=0.0;
	int quantity=0;
	int	part,chose,tdelvary;
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
			printf("================bakery part================\n");
			printf("to get product enter it num: {1-%s:%d$ ,2-%s:%d$ ,3-%s:%d$ }\nnum: ",
			names[0],prices[0],names[1],prices[1],names[2],prices[2]);
			scanf("%d",&chose);
			printf("quantity: ");
			scanf("%d",&quantity);
			
			switch(chose)
			{
				case 1 : products[0]+=quantity; break;
				case 2 : products[1]+=quantity; break;
				case 3 : products[2]+=quantity; break;
				default: printf("you Enter unvalide num!!!! please try agine\n"); break;
			}
			break;
			case 2 :
			printf("================Dairy products part================\n");
			printf("to get product enter it num: {1-%s:%d$ ,2-%s:%d$ ,3-%s:%d$ }\nnum: ",
			names[3],prices[3],names[4],prices[4],names[5],prices[5]);
			scanf("%d",&chose);
			printf("quantity: ");
			scanf("%d",&quantity);
			
			switch(chose)
			{
				case 1 : products[3]+=quantity; break;
				case 2 : products[4]+=quantity; break;
				case 3 : products[5]+=quantity; break;
				default: printf("you Enter unvalide num!!!! please try agine\n"); break;
			}
			break;
			case 3:
			printf("================vegetables part================\n");
			printf("to get product enter it num: {1-%s:%d$ ,2-%s:%d$ ,3-%s:%d$ }\nnum: ",
			names[6],prices[6],names[7],prices[7],names[8],prices[8]);
			scanf("%d",&chose);
			printf("quantity: ");
			scanf("%d",&quantity);
			
			switch(chose)
			{
				case 1 : products[6]+=quantity; break;
				case 2 : products[7]+=quantity; break;
				case 3 : products[8]+=quantity; break;
				default: printf("you Enter unvalide num!!!! please try agine\n"); break;
			}
			
			break;
			case 4 :
			printf("================fruits part================\n");
			printf("to get product enter it num: {1-%s:%d$ ,2-%s:%d$ ,3-%s:%d$ }\nnum: ",
			names[9],prices[9],names[10],prices[10],names[11],prices[11]);
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
		if(pnum>=5)
		{
			sales*=0.2;
		}
		printf("your cost is : %0.2f$\n",sales);
		printf("================================================\n");
		printf("for end selling please Enter n else Enter any key\n");
		scanf(" %c",&flag);
		
		
	}
	if(pnum<2)
	{
		printf("you must have more than 1 item to get order\n");
	}
	else
	{
		printf("delevary:\n");
		printf("1-night\n2-morning\n");
		printf("num: ");
		scanf("%d",&tdelvary);
		if(sales>10)
		{
			sales+=3;
		}
		else
		{
			sales+=2;
		}
		if(tdelvary==1)
		{
			sales+=5;
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
		if(pnum>=5)
		{
			sales*=0.2;
		}
		printf("your cost is : %0.2f$\n",sales);
		printf("================================================\n");
		printf("thank you for shoping!");
		
	}
	
	
	return 0;
}
