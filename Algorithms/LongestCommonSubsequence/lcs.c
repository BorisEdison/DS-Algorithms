#include <stdio.h>
#include <string.h>

char x[10],y[10];
char dmtx[10][10];
int mtx[10][10];

void printlcs(int i,int j){
    if(i==0 || j==0){
        return;
    }
    if(dmtx[i][j]=='d'){
        printlcs(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if (dmtx[i][j] =='u'){
        printflcs(i-1,j);
    }
    else {
        printlcs(i,j-1);
    }
}

int main() {
    printf("First String: ");
    scanf("%s",x);

    printf("Second String: ");
    scanf("%s",y);

    int xlen = strlen(x);
    int ylen = strlen(y);

    for(int i = 0; i<=xlen;i++){
        mtx[i][0] = 0;
    }

    for(int i =0;i<=ylen;i++){
        mtx[0][i] = 0;
    }

    for(int i = 1;i<=xlen;i++){
        for(int j =1;j<=ylen;j++){
            if(x[i-1]==y[i-1]){
                mtx[i][j] = mtx[i-1][j-1] + 1;
                dmtx[i][j]='d';
            }
            
            else if(mtx[i-1][j]>=mtx[i][j-1]){
                mtx[i][j] = mtx[i-1][j];
                dmtx[i][j]= 'u';
            }

            else {
                mtx[i][j] = mtx[i][j-1];
                dmtx[i][j] = 'l';
            }
        }
    }

    for(int i=0;i<xlen+1;i++){
        for(int j=0;j<ylen+1;j++){
            if(i>0 && j>0){
                printf("%c",dmtx[i][j]);
            }
            printf("%d",mtx[i][j]);
            printf("\t");
        }
        printf("\n");
    }

    pirntf("Length of LCS: %d\n",mtx[xlen][ylen]);
    printf("Subsequence: ");
    printlcs(xlen,ylen);
    printf("\n");
    return 0;
}
