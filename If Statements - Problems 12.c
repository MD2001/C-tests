#include <stdio.h>
int main (void)
{
	int num;
	printf("Enter month number: ");
	scanf("%d",&num);
	
	if(num == 2)
    {
        printf("28 or 29 days");
    }
	else if((num==1)||(num==3)||(num==1)||(num==5)||(num==7)||(num==8)||(num==10)||(num==12))
	{
		printf("31 days");
	}
	else if((num==4)||(num==6)||(num==9)||(num==11)){
		printf("30 days );
	}
	else{
		printf("Invalid input! Please enter month number between (1-12).");
	}
	return 0;
}
