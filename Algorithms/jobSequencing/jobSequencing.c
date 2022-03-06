#include <stdio.h>
int profit[100],deadline[100],list[100],job[100];

void jobS(int n){
    int key,i,tprofit=0,key1,key2;
    for(int j=1; j<n;j++){
        key = profit[j];
        key1 = deadline[j];
        key2 = job[j];
        i = j-1;
        while(i>=0 && profit[i] <key){
            profit[i+1] = profit[i];
            deadline[i+1] = deadline[i];
            job[i+1]=job[i];
            i = i-1;
        }
        profit[i+1] = key;
        deadline[i+1] = key1;
        job[i+1] = key2;
    }
    for(int i=0; i<n;i++){
        key = deadline[i];
        while (key>0){
            if(list[key-1]==0){
                list[key-1] = job[i];
                tprofit += profit[i];
                break;
            }
            else{
                key -= 1;
            }
        }
    }
    for (int i = 0; i<3;i++){
        printf("%d\t",list[i]);
    }
    printf("\nMaximum Profit: %d\n",tprofit);
}

int main(){
    int n;
    printf("\nHow many jobs do you want to enter: ");
    scanf("%d",&n);

    printf("\nEnter the profits for the job: ");
    for(int i=0; i<n;i++){
        scanf("%d",&profit[i]);
        job[i]=i+1;
    }

    printf("\nEnter the deadline for the jobs: ");
    for(int i = 0; i< n; i++){
        scanf("%d",&deadline[i]);
    }
    jobS(n);
    return 0;
}
