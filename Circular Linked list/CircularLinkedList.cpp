//circular linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head = NULL , *tail= NULL;

struct node *createNode(int data){
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next=NULL;
	return (newnode);
}

void createDummies(){
	head = createNode(0);
	tail = createNode(0);
	head->next = tail;
	tail->next = head;
}

void circularListInsertion(int data){
	struct node *newnode, *temp;
	newnode = createNode(data);
	temp = head->next;
	head ->next = newnode;
	newnode->next = temp;
}

void DeleteInCircularLinkedList(int data){
	struct node *temp0, *temp;
	if (head->next == tail && tail->next ==head){
		printf("Circular Queue/list is empty\n");
		return;
	}
	
	
	temp0 =head;
	temp = head->next;
	while(temp!=tail){
		if(temp->data == data){
			temp0->next = temp->next;
			free(temp);
			break;
		}
		temp0 = temp;
		temp = temp->next;
	}
	return;
	
}

void display(int count){
	int n = 0;
	struct node *tmp = head;
	
	if(head->next == tail && tail -> next){
		printf("Circular linked list is empty\n");
		return;
	}
	while(1){
		if(tmp == head || tmp == tail){
			if(tmp == tail){
				n++;
				printf("\n");
				if(n == count){
					break;
				}

			}
			else{
				tmp = tmp ->next;
			}
		}
		else{
			printf("%d",tmp->data);
		}
		tmp = tmp->next;	
	}
	return;
	
}

int main(){
	
	int data, ch, count;
	createDummies();
	
	while(1){
		printf("1. Insertion\t.2. Deletion\n");
		printf("3. Display\t4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: {
				printf("Enter the data to insert: ");
				scanf("%d",&data);
				circularListInsertion(data);
				break;
			}
			case 2: {
				printf("Enter the data to delete: ");
				scanf("%d",&data);
				DeleteInCircularLinkedList(data);
				break;
			}
			case 3: {
				printf("Numer of times you want to traverse: ");
				scanf("%d",&count);
				display(count);
				break;
			}
			case 4:{
				exit(0);
				break;
			}
			default:{
				printf("Please enter correct option\n");
				break;
			}
		}
		
	}
	return 0;
}

















