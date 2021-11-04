#include<stdio.h>
#include<conio.h>
#define max 7
int top,a[max];
void init(){
    top=-1;
}
int isfull(){
    if(top==6){
        return 1;
    }
    return 0;
}

void push(void){
    if (isfull()){
        printf("\nStack is full");
        return;
    }
    top++;
    printf("\ntop: %d \n",top);
    printf("\nEnter the value you want to push\n");
    scanf("%d",&a[top]);
    return;
    
}
void pop(void){
     if(top == -1){
        printf("\nStack is empty\n");
        return 0;
    }
    
    printf("\n%d",a[top]);
    top--;

}

void display(){
    if(top == -1){
        printf("\nStack is empty\n");
        return 0;
    }
    int i = top;
    for(i;i>=0;i--){
        printf("%d \t",a[i]);
    }
    return;

}
void peep(void){
    if(top == -1){
        printf("\nStack is empty\n");
        return 0;
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
