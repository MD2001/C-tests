#include <stdio.h>

void main(void)

{
	int ID,pass;
	printf("Enter ID: ");
	scanf("%d",&ID);
	switch(ID)
	{
		case 1234 : 
		printf("Enter your pass : ");
		scanf("%d",&pass);
		if(pass==4321){printf("hello mohamed"); }
		else {printf("not correct pass");}
		break;
		
		case 1111 : 
		printf("Enter your pass : ");
		scanf("%d",&pass);
		if(pass==2222){printf("hello ahmed"); }
		else {printf("not correct pass");}
		break;
		
		case 3333 : 
		printf("Enter your pass : ");
		scanf("%d",&pass);
		if(pass==4444){printf("hello omar"); }
		else {printf("not correct pass");}
		break;
		default: printf("not valied ID"); break;
	}
	
	
}
