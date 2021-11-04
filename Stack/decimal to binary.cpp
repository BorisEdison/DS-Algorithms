#include<stdio.h>
#include<conio.h>
#define max 100

int top, a[max];

void initial (void){
	top = -1;
}

void push (int x){
	if ( top == max - 1){
		printf("stack full \n");
		return ;
		
	}
	top = top + 1;
	a[top] = x;
	printf("Pushed %d sucessfully\n",x);
	return;
}
int pop ( void ){
	int rvalue;
	if ( top == -1){
		printf("Stack underflow\n");
	}
	rvalue = a[top];
	top -- ;
	return (rvalue);
}
void dtb(int n) {
	int r;
	while(n>0){
		r = n%2;
		n = n/2;
		push(r);
		
	}
	while (top > -1){
		int reply;
		reply = pop();
		printf("%d\t",reply);
		
	}
	return;
	
}
main(){
	int num;
	initial();
	printf("Enter a Number\n");
	scanf("%d",&num);
	dtb(num);
	
}


