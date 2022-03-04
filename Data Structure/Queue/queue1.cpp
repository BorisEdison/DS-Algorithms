#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
# define SIZE 100

int Queue[SIZE], rear=-1 , front=-1, data;

int isFull();
int isEmpty();
int Enqueue();
int Dequeue();
int display();

int main()
{   int choice;
	
	do
	{
	
	printf("1. Enqueu\n");
	printf("2. Dequeu\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	
	
    
	switch(choice)
	{
       	
		case 1:
			
			 		
			if (Enqueue())
			{
				printf("Entered Sucessfully\n");
			}
			else
			{
				printf(" Not Sucessful\n");
			}
			
			break;
			
		case 2:
				
			if (Dequeue())
			{
				printf("Delelted Sucessfully\n");
			}
			else
			{
				printf(" Not Deleted Sucessful\n");
			}
				
			break;
				
		case 3: 
		
		if (display())
			{
				printf("Displayed\n");
			}
		else
			{
				printf(" Cannot Sucessful\n");
			}		
		break;
				
		
		default:
			printf("Not a valid option\n");
		break;
	}
	
	printf ( "enter your choice\n");
	scanf("%d",&choice);

   } while (choice != 4);
	
	
	return 0;
}

int isFull()
{
	    if ( rear==SIZE-1)
	    {
	    	return 1;
		}
		else
		{
			return 0;
		}
}

int isEmpty()
{
	if(( (front ==-1 ) && (rear==-1) ) || (front>rear))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int Enqueue ()
{
	
	
	if ( isFull())  
	{
		printf(" QUEUE IF FULL\n");
		return 0; 
	}
	else
	{
		printf("Enter a data value to be entreted in the Queue\n");
		scanf("%d",&data);
		
		    
		    
		    if ( isEmpty())
		    {
		    	front=0;
		    	rear=0;
			}
			
		
			
			else
			{
				rear=rear+1;
			}
		
		Queue[rear]=data;
		
		printf("The data entered sucessfully is %d\n",data);
		
		return(1);
			
	}
}

int Dequeue()
{
	  if (isEmpty())
	  {
	  	printf("Queue Underflow\n");
	  	return(0);
	  }
	  
	  else
	  {
	  	   int temp;
	  	   temp = Queue[front];
	  	   
	  	   if ( front== rear)  
	  	   {
	  	   	front=-1;
	  	   	rear=-1;
		   }
		   
		   else  
		   {
		   		      front = front + 1;
		   }
		   
		   printf( "The deleted calue from queue is %d\n",temp);
		   return(1);
   
	  	   
	  }
}

int display()
{    
       if (isEmpty())
       {
       	printf("Queue Empty\n");
       	return(0);
	   }
	
		else
		{
			for (int i = front; i<= rear; i++)
			{
				printf("%d \t" ,Queue[i]);
			}
			
			return(1);
		}
}
