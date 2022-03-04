#include <stdio.h>
int a[100],min,max;
int minmax(int i,int j){
    int min1,max1;
    if(i==j){
        min=a[i];
        max=a[i];
    }
    else if(i == (j-1)){
        if(a[i] > a[j]){
            max = a[i];
            min = a[j];
        }
        else{
            min = a[i];
            max = a[j];
        }
    }
    else{
        int mid = (i+j)/2;
        minmax(i,mid);
        max1 = max;
        min1 = min;
        minmax(mid+1,j);

        if(min>min1){
            min = min1;
        }
        else if(max <max1){
            max = max1;
        }
    }
}
int main(){
    int n;
    printf("How many values do you want to insert:\t");
    scanf("%d",&n);
    printf("\nEnter the values you want to insert:\t");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    for (int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n\n");
    minmax(0,(n-1));
    printf("min = %d max = %d",min,max);
}
