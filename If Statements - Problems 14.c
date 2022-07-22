#include <stdio.h>
int main (void)
{
	int angle1,angle2,angle3;
	printf("Input first angle: ");
	scanf("%d",&angle1);
	printf("Input second  angle: ");
	scanf("%d",&angle2);
	printf("Input third  angle: ");
	scanf("%d",&angle3);
	int sum =angle1+angle2+angle3;
	
	if(sum == 180 && angle1 > 0 && angle2 > 0 && angle3 > 0) 
    {
        printf("Triangle is valid.");
    }
    else
    {
        printf("Triangle is not valid.");
    }

	return 0;
}