#include <stdio.h>
int ind = -1;

int tBS(int key, int a[],int min, int max);
int lOBS(int key, int a[],int min, int max);
int fOBS(int key, int a[],int min, int max);
int BS(int key, int a[],int min, int max);

int count=0;
int main(){
	int a[50],n,k;
	printf("How many elements do you want to insert:\t");
	scanf("%d",&n);
	for(int i=0; i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\nWhich element do you want to search:");
	scanf("%d",&k);
    int number;
    printf("\n1: Binary Search \n2: First Occurrence \n3: Last Occurrence \n4: Total Occurrence\n0: Exit");
    printf("\nWhich operation do you want to perform: ");
    scanf("%d",&number);
	int index;
    while(number != 0){
        switch(number){
            case 1:
                index = BS(k,a,0,n-1);
	            printf("\nThe element is at %d index", index);
				break;
            
            case 2:
                index = fOBS(k,a,0,n-1);
	            printf("\nThe element is at %d index", index);
				break;
            
            case 3:
                index = lOBS(k,a,0,n-1);
	            printf("\nThe element is at %d index", index);
				break;
            
            case 4:
                index = tBS(k,a,0,n-1);
	            printf("\nThe element %d occurs %d times",k, index);
				break;
        }
        printf("\nWhich operation do you want to perform: ");
        scanf("%d",&number);
    }
}

int tBS(int key, int a[], int min, int max){
	if(min > max){
		return count;
	}
	
	int mid = ((max + min) /2);
	if(a[mid] == key){
		count++;
		tBS(key,a,mid+1,max);
		tBS(key,a,min,mid-1);
	}
	else if(key>a[mid]){
		tBS(key,a,mid+1,max);
	}
	else if (key<a[mid]){
		tBS(key,a,min,mid-1);
	}
}

int lOBS(int key, int a[], int min, int max){
	if(min > max){
		return ind;
	}
	
	int mid = ((max + min) /2);
	if(a[mid] == key){
		ind = mid;
		lOBS(key,a,mid+1,max);
	}
	else if(key>a[mid]){
		lOBS(key,a,mid+1,max);
	}
	else if (key<a[mid]){
		lOBS(key,a,min,mid-1);
	}
}

int fOBS(int key, int a[], int min, int max){
	if(min > max){
		return ind;
	}
	
	int mid = ((max + min) /2);
	if(a[mid] == key){
		ind = mid;
		return fOBS(key,a,min,mid-1);
	}
	if(key>a[mid]){
		fOBS(key,a,mid+1,max);
	}
	else if (key<a[mid]){
		fOBS(key,a,min,mid-1);
	}
}

int BS(int key, int a[], int min, int max){
	if(min > max){
		return -1;
	}
	
	int mid = ((max + min) /2);
	if(a[mid] == key){
		return mid;
	}
	if(key>a[mid]){
		BS(key,a,mid+1,max);
	}
	else if (key<a[mid]){
		BS(key,a,min,mid-1);
	}
}