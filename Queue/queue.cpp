#include<stdio.h>
#include<conio.h>
#define size 100

int isEmpty();
int isFull();
int ffront();
int frear();
int enqueue();
int dequence();

int queue[size] , front = -1, rear =-1, data;

int main(){
	
	int choice = 0;
	
	while(choice !=5){
		printf("1. Enqueue \n");
		printf("2. Dequeue \n");
		printf("3. know the Front \n");
		printf("4. Know the rear \n");
		printf("5. Exit the queue \n");
		
		printf("Enter your choice \n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				int temp;
				temp=enqueue();
				
				if(temp == 1){
					printf("Sucsessful");
				}
				break;
			case 2:
				
				if(dequeue()== 1){
					printf("The element dequeue is %d",temp1);
				}
				else{
					printf("UNsuccessful as th")
				}
		}
	}
	
	return 1;
}

int isEmpty(){
	if ( (front < 0)  || (front > rear) ){
		return 1;
	}
	else{
		return 0;
	}
}
int isFull(){
	if (rear == size-1){
		return 1;
	}
	else {
		return 0;
	}
}

int enqueue (){
	int elem;
	if(isFull()){          // the queue is full
		printf("Queue overflow Exception\n");
		return 0;
	}
	else {                // element can be added in the queue
		printf("Enter a element to be inserted in the Queue\n");
		scanf("%d",&elem);
		if(front == -1 && rear == -1){      //is this the first element being inserted
			front = 0;
			rear = 0;
			
		}
		else {                         // not the first time
			rear = rear + 1;
		}
		queue[rear] = elem;      // insert int the queue
		printf("The element %d is inserted in the queue \n",elem);
		return 1;
	} 
	
}

public int dequeue(){
	if ( isEmpty()){            //is my queue empty?
		printf("Queue underflow cant dequeue from empty Queue\n");
		return (0);
	}
	else {
		int data ;
		data = queue[front];
		
		if(front == rear) {           // is that the last element in the queue, put the queue as empty
	
			front = -1;
			rear = -1;
		}
		else {
			front = front +1;
			printf("element Deleted is %d\n",data);
		}
		reutrn (1);
		     
}

int ffront(){
	if(isEmpty()){
		printf("Empty Q\n");
		return 0;
	}
	else{
		return (queue[front]);
	}
}





