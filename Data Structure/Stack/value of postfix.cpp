#include<stdio.h>
#include<conio.h>
#define size 50
#include <ctype.h>

char s[size];
int top = -1;

void push(int elem){
	s[++top] = elem;
}

int pop(){
	return(s[top--]);
	
}

main(){
	char pofx[50],ch;
	int i=0,op1,op2;
	printf("\n\nRead the Postfix Expression? ");
	scanf("%s",pofx);
	while((ch=pofx[i++]) != '\0'){
		if(isdigit(ch)){
			push(ch-'0');     //push the operand subtracting '0' from the char is casting it to an integer
			}
		else{
			op2=pop();
			op1=pop();
			
			switch(ch){
				case '+': push(op1+op2);break;
				case '=': push(op1-op2);break;
				case '*': push(op1*op2);break;
				case '/': push(op1/op2);break;
			}
			
			}
		}
	}
	
