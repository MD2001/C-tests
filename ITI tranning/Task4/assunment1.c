#include <stdio.h>

void sort(int *ptr,int sizeofarray);

int main()
{
	int arr[10]={1,5,8,7,96,3,4,5,8,2};
	sort(arr,10);
}
void sort(int *ptr,int sizeofarray)
{
	for(int i=0;i<sizeofarray-1;i++)
	{
		for(int y=0;y<sizeofarray-1-i;y++)
		{
			if(ptr[y]>ptr[y+1])
			{
			int temp=ptr[y];
			ptr[y]=ptr[y+1];
			ptr[y+1]=temp;
			}
		}
	}
	printf("sorted array :{%");
	for(int i=0;i<sizeofarray-1;i++)
	{
		printf("%d,",ptr[i]);
	}
	printf("%d}",ptr[sizeofarray-1]);
}