#include <stdio.h>
#include "STD_Types.h"
struct employee
{	
	u32 salary;
	u32 deduction;
	u32 bonus;
};
int main(void)
{	
	
	struct employee ahmed,amr,waled;
	printf("Enter salary for ahmed : ");
	scanf("%d",&ahmed.salary);
	printf("Enter bonus for ahmed : ");
	scanf("%d",&ahmed.bonus);
	printf("Enter deduction for ahmed : ");
	scanf("%d",&ahmed.deduction);
	
	printf("Enter salary for waled : ");
	scanf("%d",&waled.salary);
	printf("Enter bonus for waled : ");
	scanf("%d",&waled.bonus);
	printf("Enter deduction for waled : ");
	scanf("%d",&waled.deduction);
	
	printf("Enter salary for amr : ");
	scanf("%d",&amr.salary);
	printf("Enter bonus for amr : ");
	scanf("%d",&amr.bonus);
	printf("Enter deduction for amr : ");
	scanf("%d",&amr.deduction);
	
	int total=ahmed.salary+waled.salary+amr.salary;
	total+=ahmed.bonus+waled.bonus+amr.bonus;
	total-=(ahmed.deduction+waled.deduction+amr.deduction);
	
	printf("the total requierd is: %d",total);
	
	return 0;
}
