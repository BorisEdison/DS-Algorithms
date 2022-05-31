#include<stdio.h>

int m=0,n=4;
int cal(int temp[10][10],int t[10][10]){
    for ( int i = 0; i<n ; i++){
        for( int j =0; j<n; j++){
            if(temp[i][j]!=t[i][j]){
                m++;
            }
        }
    }
    return m;
}

int check(int a[10][10], int t[10][10]){
    int i,j,f=1;
    for(int i = 0; i<n;i++){
        for(int j = 0;j<n ; j++){
            if(a[i][j]!= t[i][j]){
                f =0;
            }
        }
    }
    return f;
}

void main(){
    int p,n=4;
    int a[10][10], t[10][10], temp[10][10], r[10][10];
    int m=0, x=0, y=0, d=1000, dmin=0, l=0;

    printf("\nEnter the matrix to be solved, space with zero: \n");
    for(int i =0; i<n;i++){
        for(int j=0; i<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nEnter the target matrix, space with zero: \n");

    for( int i = 0; i<n; i++){
        for(int j =0; j<n; j++){
            scanf("%d",&t[i][j]);
        }
    }

    printf("\nEntered Matrix is: \n");
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

    printf("\Target Matrix is: \n");
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",t[i][j]);
        }
        printf("\n");
    }

    while(!(check(a,t))){
        l++;
        d=100;
        for(int i = 0;i<n;i++){
            for(int j=0;i<n;j++){
                if(a[i][j]==0){
                    x=i;
                    y=j;
                }
            }
        }

        for(int i =0 ; i<n;i++){
            for(int j=0;j<n;j++){
                temp[i][j] = a[i][j];
            }
        }

        if(x!=0){
            p=temp[x][y];
            temp[x][y] = temp[x-1][y];
            temp[x-1][y]=p;
        }

        m=cal(temp,t);
        dmin = l + m;

        if (dmin<d){
            for(int i =0; i<n;i++){
                for(int j = 0; j<n; j++){
                    r[i][j] = temp[i][j];
                }
            }
        }

        for (int i =0; i<n;i++){
            for(int j= 0 ; j<n ; j++){
                temp[i][j] = a[i][j];
            }
        }

        if(x!=n-1){
            p = temp[x][y];
            temp[x][y] = temp[x+1][y];
            temp[x+1][y] = p;
        }

        m = cal(temp,t);
        dmin = l+ m;

        if(dmin<d){
            d = dmin;
            for( int i = 0; i<n ;i++){
                for( int j= 0 ; j<n;j++){
                    r[i][j] = temp[i][j];
                }
            }
        }

        for( int i = 0 ;i<n;i++){
            for (int j = 0; j<n; j++){
                temp[i][j] = a[i][j];
            }
        }

        if(y!=n-1){
            p = temp[x][y];
            temp[x][y] = temp[x][y+1];
            temp[x][y+1] = p;
        }

        m = cal(temp,t);
        dmin = l + m;

        if( dmin<d){
            d = dmin;
            for( int i =0 ; i<n ; i++){
                for( int j = 0 ; j< n ; j++){
                    r[i][j] = temp[i][j];
                }
            }
        }

        for( int i =0; i< n;i++){
            for( int j=0 ; j<n ; j++){
                temp[i][j] = a[i][j];
            }
        }

        if( y!=0){
            p = temp[x][y];
            temp[x][y] = temp[x][y-1];
            temp[x][y-1]=p;
        }

        m = cal( temp,t);
        dmin = l + m;

        if( dmin<d){
            d = dmin;
            for( int i = 0;i<n;i++){
                for(int j =0; j<n;j++){
                    r[i][j] = temp[i][j];
                }
            }
        }

        printf("\nCalculated Intermediate Matrix Value\n");
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                printf("%d\t",r[i][j]);
            }
            printf("\n");
        }

        for(int i = 0; i<n; i++){
            for(int j=0;j<n;j++){
                a[i][j] = r[i][j];
                temp[i][j]=0;
            }
        }
        printf("Minimum Cost: %d\n",d);

    }
}