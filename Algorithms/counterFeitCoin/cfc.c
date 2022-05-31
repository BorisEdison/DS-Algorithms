#include <stdio.h>
#include <stdlib.h>

int sum(int arr[],int l , int h){
    int total = 0;

    for(int i =l ; i<=h;i++){
        total += arr[i];
    }
    return total;
}

int cfc(int arr[],int l, int h){
    int mid = (l+h)/2;
    
    if(l==h ){
        return mid;
    }

    int lsum = sum(arr,l,mid);
    int rsum = sum(arr,mid+1,h);
    
    if (lsum==rsum && (h%2!=0)){
        printf("\nThere is no counterfeit coin");
        exit(0);
    }

    else if(lsum>rsum){
        cfc(arr,l,mid);
    }

    else{
        cfc(arr,mid+1,h);
    }

}

int main(){
    int n;
    printf("\nHow many coins you have:\t\t");
    scanf("%d",&n);

    int arr[n];
    
    printf("\nEnter weights\t");
    for(int i=0; i<n;i++){
        scanf("%d",&arr[i]);
    }

    int index = cfc(arr,0,n-1);

    printf("\nThe element is at index %d\n",index);

    return 0;
}