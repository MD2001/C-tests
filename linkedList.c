#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"

typedef struct node
{
	u32 data;
	struct node * next;
	
}node_t;
void addlinkedList(node_t* head,u32 data);
int main(void)
{	
	
	node_t* head=(node_t*)malloc(sizeof(node_t));
	node_t* ptr=head;
	head->next=NULL;
	head-> data=1;
	addlinkedList(head,5);
	addlinkedList(head,10);
	addlinkedList(head,12);
	addlinkedList(head,32);
	printf("the elment in linked list is:{");
	while(ptr->next!=NULL)
		{
			printf("%d,",ptr->data);
			ptr=ptr->next;
		}
	printf("%d}",ptr->data);
	return 0;
}
void addlinkedList(node_t* head,u32 Data)
{
	node_t* new=(node_t*)malloc(sizeof(node_t));
	new->data=Data;
	new->next=NULL;
	
	node_t* ptr=head;
	
	while(ptr->next!=NULL)
		
		{
			ptr=ptr->next;
		}
	ptr->next=new;
}