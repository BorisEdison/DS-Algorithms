#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(){
	
	int n;  //size of array to be decided at run time
	int *arr;
	
	printf("what size array do you need?\n");
	scanf("%d",&n);
	arr = (int *) malloc(n * sizeof(int));
	
	if (arr = NULL){         // unsucessul
		
		printf("Innsufficient Memory\n");
		exit(0);
	}
	else{    //sucessful part(use the memory the way you want
		prinf("Good Morning memory allocated successfully");
		
	}
	
	return 0;
}
