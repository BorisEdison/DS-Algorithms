#include<stdio.h>
#include<conio.h>

void DFS(int);

int G[10][10],visited[10],n=0;
int main()
{
  int i=0 , j=0;
  printf( "enter the Number of Vertices\n");
  scanf("%d",&n);    
  
  printf("\n Enter the Adjacency matrix of the graph\n");
  for (i = 0 ; i <n ; i++)
          for ( j = 0 ; j < n ; j++)
          scanf("%d",&G[i][j]);
  for ( i = 0 ; i <n ; i++)
              visited[i]=0;
  
        
        DFS(0);
        getch();
        return(0);
}

void DFS ( int i )
{
int j ;

printf("\n %d", i);
visited[i]=1;

             for ( j = 0 ; j<n ;j++)
             {
                if ( !visited[j] && G[i][j]==1)
                DFS(j);
      
             }
     
     
}

