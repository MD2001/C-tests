#include <stdio.h>
int main (void)
{
	  float basic, gross, da, hra;
    printf("Enter basic salary of an employee: ");
    scanf("%f", &basic);
    if(basic <= 10000)
    {   da  = basic * 0.8;
        hra = basic * 0.2;
    }
    else if(basic <= 20000){
        da  = basic * 0.9;
        hra = basic * 0.25;
    }
    else{
        da  = basic * 0.95;
        hra = basic * 0.3;
    }
    gross = basic + hra + da;
    printf("GROSS SALARY OF EMPLOYEE = %.2f", gross);
	return 0;
}