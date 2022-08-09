#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"

typedef struct node
{
	u32 data;
	struct	node *next;
}node_t;


int main()
{
	u8 choice,value=0;
	u32 i=1;
	node_t * head =(node_t*)malloc(sizeof(node_t));
	head->next=NULL;
	node_t * ptr=head;	
	
	while(choice!=2)
	{
	printf("To add node Enter 0\n");
	printf("To print the linked list Enter 1\n");
	printf("To exit press 2\n");
	printf("your choice: ");
	scanf("%d",&choice);
	
	
		switch(choice)
		{
			case 0:
			printf("please Enter node value: ");
			scanf("%d",&value);
			ptr->data=value;
			node_t * node =(node_t*)malloc(sizeof(node_t));
			node->next=NULL;
			ptr->next=node;
			ptr=node;
			printf("thank you\n");
			break;
			
			case 1 :
			i=1;
			node_t* reader=head;
			printf("=================================\n");
			if(reader->next==NULL)
			{
				printf("list is Empty\n");
			}
			else{
				while(reader->next!=NULL)
				{
					printf("node number %d : %d\n",i,reader->data);
					reader=reader->next;
					i++;
				}
			}
			printf("=================================\n");
			break;
			
			case 2: break;
			default : printf("invalid choice please try agine\n");
			
		}
	}
	printf("thank you ");
	return 0;
}