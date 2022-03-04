#include<stdio.h>
#include<stdlib.h>

void insert_first();
void delete_first();

void display();

void insert_last();
void delete_last();

void delete_specific();

struct node{
	int info;
	struct node *link;
} *start = NULL;

int item;

main(){
	int ch;
	do{
		printf("\n\n\n1. Insert First\n2. Display \n3. Delete First \n4. Insert Last \n5. Delete Last\n6. Delete Specific\n7. Exit\n");
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

void insert_first(){
	struct node *ptr;
	printf("\n\nEnter item: ");
	scanf("%d",&item);
	
	if(start == NULL){
		start = (struct node* )malloc(sizeof(struct node));
		start->info = item;
		start->link = NULL;
	}
	else{
		ptr = start;
		start = (struct node *)malloc (sizeof(struct node));
		start->info = item;
		start->link = ptr;
	}
	printf("\nItem inserted: %d\n",item);
}
void display(){
	struct node *ptr = start;
	int i=0;
	if(ptr == NULL){
		printf("\nLinkedList is empty.\n");
		
	}
	else{
		printf("\nSr. No. \t\tAddress\t\tInfo\t\tLink\n");
		while(ptr != NULL){
			printf("\n%d.\t\t%d\t\t%d\t\t%d\n",i,ptr,ptr->info,ptr->link);
			ptr = ptr->link;
			i++;
		}
		printf("\n\nTotal number of Nodes is %d",i);
	}
}
void delete_first(){
	struct node *ptr;
	if(start == NULL){
		printf("\n\nLinked List is empty.\n");
	}
	else{
		ptr = start;
		item = start->info;
		start = start->link;
		
		free(ptr);
		printf("\n\nItem deleted: %d",item);
	}
}

void delete_last(){
	struct node *ptr,*prev;
	if(start == NULL){
		printf("\n\nLinkedList is empty.\n");
	}
	else{
		ptr= start;
		prev = start;
		while(ptr->link != NULL){
			prev = ptr;
			ptr = ptr->link;
		}
		item = ptr->info;
		
		if (start-> link == NULL){
			start = NULL;
		}
		else{
			prev->link = NULL;
		}
		
		printf("\n\nItem deleted: %d",item);
	}
	
}


void insert_last(){
	struct node *ptr;
	
	printf("\n\nEnter item: ");
	scanf("%d",&item);
	
	if(start == NULL){
		start = (struct node*) malloc(sizeof(struct node));
		start->info = item;
		start->link = NULL;
	}
	else{
		ptr = start;
		
		while (ptr->link != NULL){
			ptr = ptr->link;
		}
		ptr->link = (struct node*)malloc(sizeof(struct node));
		
		ptr = ptr ->link;
		ptr->info = item;
		ptr->link = NULL;
		printf("\nItem Inserted: %d\n",item);
	}
}

void delete_specific(){
	struct node *ptr,*prev;
	
	printf("\n\nEnter Item which is to be deleted: ");
	scanf("%d",&item);
	
	if(start == NULL){
		printf("\n\nLinkedList is empty.\n");
		
	}
	else if (start->info == item){
		ptr = start;
		start = start->link;
	}
	else{
		ptr = start;
		prev = start;
		while(ptr != NULL){
			if(ptr->info  == item){
				prev->link = ptr->link;
				free(ptr);
			}
			else{
				prev = ptr;
				ptr = ptr->link;
			}
		}
		printf("\n\nItem deleted: &d",item);
		
	}
}














