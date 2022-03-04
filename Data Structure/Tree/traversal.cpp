#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct bin{
	int data;
	struct bin *left;
	struct bin *right;
}node;       

void insert ( node *,node *);
void inorder (node *);
void preorder (node *);
void postorder (node *);
node* get_node();

int main(){
	int choice;
	char ans = 'n';
	node *New, *root;
	root = NULL;
	do{
		printf("Program for implementing simple binary tree\n");
		printf("1. Create\n");
		printf("2. Inorder \n");
		printf("3. Preorder\n");
		printf("4. Postorder\n");
		printf("Exit: \n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		
		printf("Enter your choice\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:{
				do{
					NEW = get_node();
					printf("\nEnter the Element\n");
					scanf("%d",&New->data);
					
					if(root==NULL){
						root=New;
					}
					else{
						insert(root,New);
					}
					
					printf("\nWant to enter more elements? (Y/N)\n");
					ans=getche();
				} while(ans == 'Y' || ans == 'y');
				break;
			}
			
			case 2:{
				if(root==NULL){
					printf("\ntree not created\n");
				}
				else{
					inorder(root);
				}
				break;
			}
			case 3:{
				if(root==NULL){
					printf("\ntree Not Created\n");
				}
				else{
					preorder(root);
				}
				break;
			}
			case 4:{
				if(root==NULL){
					printf("\ntree not created\n");
				}
				else{
					postorder(root);
				}
				break;
			}
			case 5:{
				exit(0);
				break;
			}
		}
	}while(choice!=5);
	getch
	return(0);
}

node* get_node(){
	node* temp;
	temp = (node *)malloc(sizeof(node));
	temp->left=NULL;
	tmep->right=NULL;
	
	return temp;
}




void insert(node *root,node* New){
	char ch;
	printf("Where to insert left/right of %d\n",root->data);
	ch = getche();
	if((ch=='r') || (ch == 'R')){
		if(root->right == NULL){
			root->right=New;
			
		}
		else{
			insert(root->right,New)
		}
	}
	else{
		if(root->left == NULL){
			root->left = New;
		}
		else{
			insert(root->left,New);
		}
	}
}


void inorder(node *temp){
	
	if(temp!=NULL){
		inorder(temp->left);
		printf("%d\t",temp->data);
		inorder(temp->right);
		printf("\n");
	}
}

void preorder(node *temp){
	if(temp!=NULL){
		printf("%d\t",temp->data);
		preorder(temp->left);
		preprder(temp->right);
		printf("\n"))
	}
}

void postorder(node *temp){
	if(temp!=NULL){
		postorder(temp->left);
		postorder(tmep->right);
		printf("%d\t",temp->data);
		printf("\n");
	}
}




















