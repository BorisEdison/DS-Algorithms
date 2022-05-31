#include <stdio.h>
#include <string.h>
char x[10],y[10];
char cmtx[10][10];
int mtx[10][10];

void printlcs(int i,int j){
    if(i==0 || j==0) {
        return;
    }
    if(cmtx[i][j]=='d'){
        printlcs(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(cmtx[i][j]=='u'){
        printlcs(i-1,j);
    }
    else{
        printlcs(i,j-1);
    }
}

int main() {
    
    printf("First string: ");
    scanf(" %s",x);
    printf("Second string: ");
    scanf(" %s",y);


    int xlen=strlen(x);
    int ylen=strlen(y);
    printf("\n");

    for(int i=0;i<=xlen;i++) {
        mtx[i][0]=0;
    }

    for(int i=0;i<=ylen;i++) {
    mtx[0][i]=0;
    }

    for(int i=1;i<=xlen;i++){
        for(int j=1;j<=ylen;j++) {
            if(x[i-1]==y[j-1]) {
                mtx[i][j]=mtx[i-1][j-1]+1;
                cmtx[i][j]='`';
            }

            else if(mtx[i-1][j]>=mtx[i][j-1]) {
                mtx[i][j]=mtx[i-1][j];
                cmtx[i][j]='^';
            }
 
            else {
                mtx[i][j]=mtx[i][j-1];
                cmtx[i][j]='<';
            }
        }
    }

    for(int i=0;i<xlen+1;i++){
        for(int j=0;j<ylen+1;j++){

            if (i>0 && j>0) {
            printf("%c",cmtx[i][j]);
            }

            printf("%d",mtx[i][j]);
            printf("\t");
        }
        printf("\n");
    }

    printf("Length of LCS: %d\n",mtx[xlen][ylen]);
    printf("Subsequence: MNLM" );
    printlcs(xlen,ylen);
    printf("\n");

    return 0;
}