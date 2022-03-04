#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct customer{
	int cust_id;
	char name[30];
	char add[30];
	struct customer *next;	
}node;

node *start = NULL;

node *create_node(){
	return((node *)malloc(sizeof(node)));
	}

void insert_first(){
	int cust_id;
	char name[30],add[30];
	
	node*p;
	
	printf("\nEnter Customer ID, Name and Address: ");
	scanf("%d %s %s",&cust_id,&name,&add);
	
	p = create_node();
	p->cust_id = cust_id;
	strcpy(p->name,name);
	strcpy(p->add,add);
	
	p->next = NULL;
	
	if(start == NULL){
		start = p;
	}
	else{
		p->next = start;
		start = p;
	}
}

void insert_last(){
	int cust_id;
	char name[30],add[30];
	node *p;
	
	printf("Enter Customer ID, Name and Address: ");
	
	scanf("%d %s %s",&cust_id,&name,&add);
	
	p=create_node();
	p->cust_id = cust_id;
	strcpy(p->name ,name);
	strcpy(	p->add, add);
	
	node *ptr;
	ptr = start;
	while(ptr->next!=NULL){
		ptr = ptr->next;
	}
	ptr->next = p;
	p->next = NULL;
}

void delete_first(){
	node *ptr;
	if(start == NULL){
		printf("\n\nLinked list is empty.\n");
		
	}
	else{
		ptr = start;
		int cust_id = start->cust_id;
		char name[30],add[30];
		strcpy(name,start->name);
		strcpy(add,start->add);
		start = start->next;
		free(ptr);
		printf("\n\nItem deleted Customer ID: %d \t Name: %s \t Address: %s",cust_id,name,add);
		
		
	}
}

void delete_last(){
	node *ptr,*prev;
	if(start == NULL){
		printf("\n\nLinkled List is empty.\n");
	}
	else{
		ptr = start;
		prev = start;
		while(ptr->next != NULL){
			prev = ptr;
			ptr = ptr->next;
			
		}

		int cust_id = ptr->cust_id;
		char name[30],add[30];
		strcpy(name,ptr->name);
		strcpy(add,ptr->add);
		
		if( start->next == NULL){
			start=NULL;
		}
		else{
			prev->next = NULL;
			free(ptr);
		}
		
		printf("\n\nItem deleted Customer ID: %d \t Name: %s \t Address: %s",cust_id,name,add);
		
	}
}
void delete_specific(){
	node *ptr, *prev;
	int item;
	printf("\n\nEnter the item which is to be deleted: ");
	scanf("%d",&item);

	char name[30],add[30];

	
	if(start == NULL){
		printf("\n\nLinked List is empty.\n");
		
	}
	else if(start->cust_id == item){
		ptr=start;
		start = start->next;
		strcpy(name,ptr->name);
		strcpy(add,ptr->add);
		printf("\n\nItem deleted Customer ID: %d \t Name: %s \t Address: %s",item,name,add);
		free(ptr);
	}
	else{
		ptr = start;
		prev = start;
		while(ptr!= NULL){
			if(ptr->cust_id == item){
				prev->next = ptr->next;

			
				break;
				
			}
			else{
				prev = ptr;
				ptr = ptr->next;
			}
		}
		strcpy(name,ptr->name);
		strcpy(add,ptr->add);
		printf("\n\nItem deleted Customer ID: %d \t Name: %s \t Address: %s",item,name,add);
		free(ptr);
		
	}
}

void display(){
	node *ptr = start;
	if(ptr == NULL){
		printf("\nLinkedList is empty.");
	}
	else{
		printf("\nCustomer ID \t\tName \t\tAddress\n");
		
		while(ptr != NULL){
			printf("%d \t\t%s \t\t%s",ptr->cust_id,ptr->name,ptr->add);
			ptr=ptr->next;
		}
	}
}

int main(){
	int ch;
	do{
		printf("\n1. Insert First\n2. Display \n3. Delete First \n4. Insert Last \n5. Delete Last\n6. Delete Specific\n7. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:{
				insert_first();
				break;
			}
			case 2:{
				display();
				break;
			}
			case 3:{
				delete_first();
				break;
			}
			case 4:{
				insert_last();
				break;
			}
			case 5:{
				delete_last();
				break;
			}
			case 6:{
				delete_specific();
				break;
			}
			case 7:{
				exit(0);
				break;
			}
			default:{
				printf("\n\nInvalid choice. Please try again.\n");
				break;
			}
			
		}
	}while(1);
}









