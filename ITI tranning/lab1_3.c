#include <stdio.h>

void main(void)

{
	int ID,pass,counter=0;
	printf("Enter ID: ");
	scanf("%d",&ID);
	switch(ID)
	{
		case 1234 : 
		printf("Enter your pass : ");
		scanf("%d",&pass);
		if(pass==4321){printf("hello mohamed"); }
		else {while((pass!=4321)&&(counter<3))
			{
				printf("Wrong password try agine : ");
				scanf("%d",&pass);
				if(pass==4321){printf("hello mohamed"); break; }
				counter++;
			}}
		break;
		
		case 1111 : 
		printf("Enter your pass : ");
		scanf("%d",&pass);
		if(pass==2222){printf("hello ahmed"); }
		lse {while((pass!=2222)&&(counter<3))
			{
				printf("Wrong password try agine : ");
				scanf("%d",&pass);
				if(pass==2222){printf("hello mohamed"); break; }
				counter++;
			}}
		break;
		
		case 3333 : 
		printf("Enter your pass : ");
		scanf("%d",&pass);
		if(pass==4444){printf("hello omar"); }
		lse {while((pass!=4444)&&(counter<3))
			{
				printf("Wrong password try agine : ");
				scanf("%d",&pass);
				if(pass==4444){printf("hello mohamed"); break; }
				counter++;
			}}
		break;
		default: printf("not valied ID"); break;
	}
	
	
}
