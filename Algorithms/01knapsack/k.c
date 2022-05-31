#include<stdio.h>
#include<stdlib.h>


int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
void knapsack(int profit[],int weight[],int n,int cap){
    int mtx[n+1][cap+1];

    for(int i=0; i < n+1;i++){
        mtx[i][0]=0;
    }

    for(int j=0; j< cap+1;j++){
        mtx[0][j]=0;
    }

    for(int i=1; i< n+1; i++){
        for(int j=0; j<cap+1;j++){
            if((j-weight[i]) >= 0){
                mtx[i][j]= max( mtx[i-1][j] , profit[i]+mtx[i-1][j-weight[i]]);
            }
            else{
                mtx[i][j]=mtx[i-1][j];
            }
        }
    }

    for(int i=0; i< n+1; i++){
        for(int j=0; j<cap+1;j++){

            printf("%d\t", mtx[i][j]);
        }
        printf("\n");
    }
    
    printf("\nSelect: ");
    
    int j=n;
    for(int i=n;i>=1;i--){
        if (mtx[i][j]!=mtx[i-1][j]){
            printf("%d\t ",j);
            j=j-weight[i];
            }
    }

}

int main(){
    int n,cap;
    printf("\nHow many items do you have? ");
    scanf("%d",&n);
    int profit[n+1],weight[n+1];

    printf("\nEnter maximum weight: ");
    scanf("%d",&cap);
    fflush(stdin);
    profit[0]=0;
    weight[0]=0;
    
        printf("\nEnter weights: ");
    for(int i=0; i<n;i++){
        scanf("%d",&weight[i+1]);
    }

    printf("\nEnter profits: ");
    for(int i=0; i<n;i++){
        scanf("%d",&profit[i+1]);
    }

    printf("\n\n");
    
    knapsack(profit,weight,n,cap);

    return 0;
}

