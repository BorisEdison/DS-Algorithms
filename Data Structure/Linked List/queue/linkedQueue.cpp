#include<stdio.h>
#include<stdlib.h>

struct node{
	int Data;
	struct node *next;
};

struct node *front = NULL, *rear=NULL;

struct node * createNode( int data){
	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->Data = data;
	newnode->next = NULL;
	return(newnode);
}

void enqueue (int data){
	
	struct node *ptr = createNode(data);
	if (rear == NULL){   //rear == NULL is this the very first element in the queue
		
		front = rear = ptr;
		return;
	} 
	
	rear->next = ptr;
	rear = ptr;
}

void dequeue(){
	struct node * tmp;
	
	if(front == NULL){   //(front == NULL ) - Empty Queue
		
		printf("Queue is empty\n");
		return;
	}
	
	else if(front == rear){      // only one node in queue
		
		tmp = front;
		front = rear = NULL;
	}
	else {
		tmp = front;
		front = front->next;
	}
	free(tmp);
	return;
}

void display(){
	
	struct node *tmp;
	
	if (front == NULL) {
		printf("Queue is empty\n");
	}
	else{    // there are elements in the queue
		
		tmp = front;
		while(tmp){
			printf("%3d",tmp->Data);
			tmp = tmp->next;
		}
		printf("\n");
	}
	return;
}

int main(){
	
	int data,ch;
	
	while(1){
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter Your choice");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:{
				printf("Enter the number you want to insert: ");
				scanf("%d",&data);
				enqueue(data);
				break;
			}
			
			case 2:{
				dequeue();
				break;
			}
			
			case 3:{
				display();
				break;
			}
			case 4:{
				exit(0);
			}
			
			default:{
				printf("Please enter correct option\n");
				break;
			}
				
		}
	}
	return 0;
}















