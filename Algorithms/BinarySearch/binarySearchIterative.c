#include <stdio.h>
int a[100];
int iBS (int a[], int p, int r, int key){
    while (p <= r){
        int middle = p + (r- p )/2;
        if (a[middle] == key)
            return middle;
        if (a[middle] < key)
            p = middle + 1;
        else
            r = middle - 1;
        }
        return -1;
    }
int main(void){
    int n;
    printf("Enter no. of elements you want to insert: ");
    scanf("%d",&n);
    printf("Enter elements\n");

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int x ;
    printf("Enter the element to be searched");
    scanf("%d",&x);
    int found_index = iBS(a, 0, n-1, x);

    if(found_index == -1 ) {
        printf("Element not found in the array ");
    }
    else {
        printf("Element found at index : %d",found_index);
    }
    return 0;
    }