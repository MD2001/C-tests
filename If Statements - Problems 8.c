#include <stdio.h>
int main (void)
{
	char character;
	printf("Input character: ");
	scanf("%c",&character);
	
	 if((character=='a' || character=='e' || character=='i' || character=='o' || character=='u' || 
       character=='A' || character=='E' || character=='I' || character=='O' || character=='U'))
	{
		  printf("'%c' is vowel",character);
	}
	else{
		  printf("'%c' is not vowel",character);
	}
	
	return 0;
}