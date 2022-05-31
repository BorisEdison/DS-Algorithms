#include<stdio.h>
#include<time.h>

void quicksort( int number[25],int first,int last){
 int i ,j,pivot,temp;

 if(first<last){
     pivot = first;
     i = first;
     j = last;

     while(i<j){
         while (number[i]<=number[pivot] && i<last){
             i++;
         }
         while(number[j]>number[pivot]){
             j--;
         }
         if(i<j){
             temp = number[i];
             number[i] = number[j];
             number[j] = temp;
         }
     }
     temp = number[pivot];
     number[pivot] = number[j];
     number[j] = temp;
     quicksort(number,first,j-1);
     quicksort(number,j+1,last);;
     
 }
}

int main(){
    int i, count = 15, number[25],c;
    clock_t start,end;
    double cpu_time_used;
    start = clock();

    printf("Enter the input size");
    scanf("%d", &count);
    srand(time(0));

    for(c =0; c<count;c++){
        number[c] = rand()%100+1;
        printf("%d\n",number[c]);
    }

    quicksort(number,0,count);
    printf("Order of sorted elements: \n");

    for(int i =0;i<count;i++){
        printf("%d\n",number[i]);
    }
    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n\nTime Taken = %f\n", cpu_time_used);
    return 0;

}