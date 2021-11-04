#include<stdio.h>
#include<string.h>
#define max 100
int top, stack[max];

void push (char x){
	
	//Push (inserting element in stack) operation
	if(top == max - 1){
		printf("Stack overlow");
		
	}
	else{
		stack[++top] = x ;
	}
	
}
void pop(){
	//Pop (removing element from Stack)
	printf("%c",stack[top--]);
}

main(){
	char str [12];
	printf("Enter a String: ");
	gets  (str);
	int len = strlen(str);
	int i;
	
	for(i=0 ; str[i] != '\0' ; i++){
		push(str[i]);
	}
	for(i=0; i<len;i++)
		pop();
}
