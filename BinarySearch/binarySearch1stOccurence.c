#include <stdio.h>

int BS(int key, int a[],int min, int max);
int ind = -1;
int main(){
	int a[50],n,k;
	printf("How many elements do you want to insert:\t");
	scanf("%d",&n);
	for(int i=0; i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\nWhich element do you want to search:");
	scanf("%d",&k);
	int index = BS(k,a,0,n-1);
	printf("The element is at %d index", index);
}

int BS(int key, int a[], int min, int max){
	if(min > max){
		return ind;
	}
	
	int mid = ((max + min) /2);
	if(a[mid] == key){
		ind = mid;
		return BS(key,a,min,mid-1);
	}
	if(key>a[mid]){
		BS(key,a,mid+1,max);
	}
	else if (key<a[mid]){
		BS(key,a,min,mid-1);
	}
}


