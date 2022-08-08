#include <stdio.h>
#include "STD_TYPES.h"

typedef struct
{
	u8 ID;
	u8 Math;
	u8 Language;
	u8 Physics;
	u8 Chemistry;
}student;

int main()
{
	student class[10] = {
		{50,60,70,80,90}  , 
		{100,98,95,91,80} , 
		{47,66,60,51,95}  , 
		{60,36,50,18,85}  ,
		{90,94,89,96,67}  ,
		{70,80,99,84,90}  , 
		{46,50,42,60,20}  , 
		{78,64,51,81,86}  , 
		{66,88,63,80,30}  , 
		{64,67,69,85,87}    
	};
	u8 id,found=0;
	printf("Enter id: ");
	scanf("%d",&id);
	for(int i=0;i<10;i++)
	{
		if(class[i].ID==id)
		{
			printf("===================================\n");
			printf("Math : %d\n",class[i].Math);
			printf("Language : %d\n",class[i].Language);
			printf("Physics : %d\n",class[i].Physics);
			printf("Chemistry : %d\n",class[i].Chemistry);
			found=1;
		}
	}
	if(found==0)
	{
		printf("please try agine ");
	}
	
	
	
	return 0;
}