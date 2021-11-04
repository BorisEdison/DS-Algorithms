#include<stdio.h>
#include<conio.h>
#define max 7
int top,a[max];
void init(){
    top=-1;
}
void push(void){
    if (isfull()){
        printf("Stack is full");
        return;
    }
    top++;
    printf("Enter the value you want to push");
    scanf("%d",a[top]);
    return;
    
}
void pop(void){
    if(isempty()){
        printf("Stack is empty");
        return;
    }
    printf("\n%d",a[top]);
    top--;

}
int isfull(void){
    if(top==max-1){
        return 1;
    }
    return ;
}
int isempty(void){
    if(top==-1){
        return 1;
    }
    return ;
}
void display(void){
    if(isempty){
        printf("\nStack is empty");
        return;
    }
    int i = top;
    for(i;i>=0;i--){
        printf("%d \t",a[i]);
    }
    return;

}
void peep(void){
    if (isempty){
        printf("\nStack is empty");
        return;
    }
    printf("%d is the value at the top",a[top]);
    return;

}

int main(){
    init();
    printf("\nFor Push: 1\nFor Pop: 2");
    printf("\nFor Peep: 3\nFor Display: 4");
    printf("\nTo exit: 5");
    
    int co;
    int i =1;
    for(i;i<100 ; i++){
        printf("\n\nEnter character to perform respective command:\n");
        scanf("%d",&co);
		printf("\n%d",co);
        if(co == 1 ){
            push();
            continue;
        }
         if(co == 2){
            pop();
            continue;
        }
         if(co== 3){
            peep();
            continue;
        }
         if(co == 4){
            display();
            continue;
        }
        if(co == 5){
            break;
        }
        else{
            printf("\nEnter a valued command:");
            continue;
        }
    }
    return 0;


    
}
