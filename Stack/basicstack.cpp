#include<stdio.h>
#include<conio.h>
#define max 5          //size of the stack

int top, a[max];
 
void push(void){
	int x;
	if(top == max -1){         //condition for checking stack is full
		printf("Stack overlow\n");
		return;
	}
	printf("enter a no\n");
	scanf("%d",&x);
	a[++top] = x;            // increment the top and inserting element
	printf("%d succ. pushed\n",x);
	return;
}
void pop( void){
	int y;
	if( top == -1){                           // condition for checking If stack is empty
		printf("Stack is empty\n");
		return;
	}
	y = a[top];
	a[top--] = 0 ;                       // insert 0 at the place of removing element and decrement the top
	printf("%d succ. poped\n,y");
	return;
}
void display(void){
	int i;
	if(top == -1){
		printf("stack is empty\n");
		return;
	}
	printf("elements of the stack are:\n");
	for (i=0; i<=top;i++){
		printf("%d\n",a[i]);
		return;
	}
}
int main(){
	int c;
	top=-1;
	do{
		printf("1: Push\n2: Pop\n3: display\n4: exit\nchoice:");
		scanf("%d",&c);
		switch(c){
			case 1: push();
			break;
			case 2: pop();
			break;
			case 3: display();
			break;
			case 4: printf("Pgm ends\n");
			break;
			default : printf("wrong choice\n");
			break;
		}
	}while(c!=4);
	return 0;
}











