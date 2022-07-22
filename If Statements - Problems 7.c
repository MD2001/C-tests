#include <stdio.h>
int main (void)
{
	char character;
	printf("Input character: ");
	scanf("%c",&character);
	
	 if((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
	{
		  printf("'%c' is alphabet",character);
	}
	else{
		  printf("'%c' is not alphabet",character);
	}
	
	return 0;
}