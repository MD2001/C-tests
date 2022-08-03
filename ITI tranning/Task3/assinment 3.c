#include <stdio.h>

int main()
{
	int max=0,min;
	int arr[10];
	for (int i=0;i<10;i++)
	{
		printf("Enter num %d : ",i);
		scanf("%d",&arr[i]);
		if(arr[i]>max) max=arr[i];
		if(arr[i]<min) min=arr[i];
	}
	printf("max is : %d\n",max);
	printf("min is : %d\n",min);
}