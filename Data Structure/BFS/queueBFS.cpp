#include<stdio.h>
#include<conio.h>
#define MAX 10

typedef struct Q
{
  int R,F;
  int data[MAX];   
}Q;

int empty( Q *p);
int full ( Q *p); 
void enqueue( Q *p, int x); 
int dequeue( Q *p); 
void BFS(int);
int G[MAX][MAX]; 
int n;
int main()
{
     int i,j,v;
     
     printf("Enter the number of vertices\n");
     scanf("%d",&n);
     
     printf("\n Enter the Adjacency Matrix of the graph\n");
     
     for(i = 0 ; i<n ; i++)
         for ( j = 0 ; j<n ; j++)
         scanf("%d",&G[i][j]);
         
     printf("Enter the starting vertex for BFS\n");
     scanf("%d",&v);
     BFS(v); 
         
     getch();
return 0;
}

void BFS( int v)
{
    int visited[MAX],i;
    
    Q q;
    
    q.R=q.F=-1;
         
    for (i=0;i<n;i++)
    visited[i]=0;
    
    enqueue(&q,v); 
    printf("\n visit \t%d",v);
    
    visited[v]=1;
    
    while(! empty(&q))
    {
         v = dequeue(&q); 
         
         for(i=0;i<n;i++)
         
              if (visited[i]==0 && G[v][i]!=0)
              {
                  enqueue(&q,i); 
                  visited[i]=1;
                  printf("\n\t %d",i);                  
              } 
            
    }
}

int empty ( Q *P)
{
      if (P->R==-1)
      return (1);
      return (0);    
    
}

int full(Q *P)
{
     if(P->R==MAX-1)
     return(1);
     
     return(0);    
}

void enqueue( Q *P, int x)
{
   if(P->R ==-1)
   {
      P->R=P->F==0;
      P->data[P->R]=x;        
   }
   else
   {
   P->R=P->R+1;
   P->data[P->R]=x;    
   }        
}

int dequeue(Q *P)
{
  int x;
  x= P->data[P->F];
  
  if(P->R==P->F)
  {  
     P->R=-1;
     P->F=-1;    
  }

  else
  P->F= P->F +1;
  return(x);
}    

