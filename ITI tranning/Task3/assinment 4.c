#include <stdio.h>

int main()
{
	int passed=0,Failed=0,Highest=0,Lowest=0,sum=0;
	int class1[10]={99,25,68,30,90,80,70,50,30,85};
	int class2[10]={89,25,50,30,85,77,12,70,11,100};
	int class3[10]={99,25,68,30,90,30,85,48,68,35};
	for(int i=0;i<10;i++)
	{
		
		if(class1[i]>=50) passed++;
		if(class1[i]<=50) Failed++;
		if(class1[i]>Highest) Highest=class1[i];
		if(class1[i]<Lowest) Lowest=class1[i];
		sum+=class1[i];
	}
	printf("Number of passed students in class1 :%d\n",passed);
	printf("Number of Failed students in class1 :%d\n",Failed);
	printf("Highest grade in class1 :%d\n",Highest);
	printf("Lowest grade in class1 :%d\n",Lowest);
	printf("Average grade in class1 :%d\n",sum/10);
	printf("=============================================\n");
	passed=0,Failed=0,Highest=0,Lowest=100,sum=0;
	for(int i=0;i<10;i++)
	{
		
		if(class2[i]>=50) passed++;
		if(class2[i]<=50) Failed++;
		if(class2[i]>Highest) Highest=class2[i];
		if(class2[i]<Lowest) Lowest=class2[i];
		sum+=class2[i];
	}
	printf("Number of passed students in class2 :%d\n",passed);
	printf("Number of Failed students in class2 :%d\n",Failed);
	printf("Highest grade in class2 :%d\n",Highest);
	printf("Lowest grade in class2 :%d\n",Lowest);
	printf("Average grade in class2 :%d\n",sum/10);
	printf("=============================================\n");
	passed=0,Failed=0,Highest=0,Lowest=100,sum=0;
	for(int i=0;i<10;i++)
	{
		
		if(class3[i]>=50) passed++;
		if(class3[i]<=50) Failed++;
		if(class3[i]>Highest) Highest=class3[i];
		if(class3[i]<Lowest) Lowest=class3[i];
		sum+=class3[i];
	}
	printf("Number of passed students in class3 :%d\n",passed);
	printf("Number of Failed students in class3 :%d\n",Failed);
	printf("Highest grade in class3 :%d\n",Highest);
	printf("Lowest grade in class3 :%d\n",Lowest);
	printf("Average grade in class3 :%d\n",sum/10);
	printf("=============================================\n");
}