#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
int main(void)
{	
	int elment,temp;
	printf("Enter your number of elments: ");
	scanf("%d",&elment);
	int* arr=(int*)malloc(elment*4);
	
	for(int i=0;i<elment;i++)
	{
		printf("Enter elment num %d:",i);
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<elment-1;i++)
	{
		for(int y=0;y<elment-i;y++)
		{
			if(arr[y]>arr[y+1])
			{
				temp=arr[y];
				arr[y]=arr[y+1];
				arr[y+1]=temp;
			}
		}			
	}
	
		printf("your elment is :{");
		for(int i=0;i<elment-1;i++)
		{
			printf("%d,",arr[i]);
		}
		printf("%d}",arr[elment-1]);
		
	
	
	return 0;
}
