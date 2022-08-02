#include <stdio.h>
int main()
{
	int temp;
	int arr[10];
	for(int i=0;i<10;i++)
	{
		printf("Enter num: ");
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<9;i++)
	{
		for(int y=0;y<9-i;y++)
		{
			if(arr[y]>arr[y+1])
			{
				temp=arr[y];
				arr[y]=arr[y+1];
				arr[y+1]=temp;
			}
		}
	}
	
	for(int i=0;i<10;i++)
	{
		printf("%d\n",arr[i]);
		
	}
}