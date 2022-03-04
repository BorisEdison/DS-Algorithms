#define size 50
#include <ctype.h>
#include <stdio.h>

char s[size];

int top = -1; 

void push (char elem){
	s[++top] = elem;
}

char pop(){
	return(s[top--]);
}
int pr(char oper){
	switch (oper) {
		case '#':
			return 0;
		case '(':
			return 1;
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 3;
			
	}
}
main(){
	char infx[50],pofx[50],ch,oper;
	int i =0 ,k=0;
	printf("\n\nRead the Infix Expression?");
	scanf("&s",infx);
	push('#');
	while ( (infx[i++]) != '\0'){
		ch = infx[i++];
		if (ch == '('){
			push(ch);
		}
		else if (isalnum(ch)){
			pofx[k++] = ch;
		}
		else if(ch == ')'){
			while (s[top] != '('){
				pofx[k++] = pop();
				
			}
			pop();
		}
		else{
			while(pr(s[top]) >=  pr(ch)){
				pofx[k++] = pop();
				
			}
			push(ch);
		}
	}
	k=0;
	while(s[top] != '#' )
		pofx[k++] = pop();
	pofx[k] = '\0';
	printf("\n\nGiven Infix Expn: %s Postfix Expn: %s\n",infx,pofx);
}
