#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
	int id;
	char name[30];
	int semester;
	struct student *link;
}node;

node *header = NULL;

node *get_node(){
	return((node *)malloc(sizeof(node)));
}

void insert(){
	int id, semester;
	char name[30];
	node *p;
	printf("Enter ID, Name and Semester: ");
	scanf("%d %s %d",&id,&name,&semester);
	
	p = get_node();
	
	p->id = id;
	
	p->semester = semester;
	strcpy(p->name ,name);
	
	p->link=NULL;
	if(header==NULL){
		header = p;
	}
	else{
		p->link = header;
		header = p;
	}
	
}
void del(){
	node* temp;
	
	if(header == NULL){
		printf("Empty List\n");
		return;
	}
	else{
		temp = header;
		header = header->link;
		printf("The following record is deleted: %d %s %d\n", temp->id,temp->name,temp->semester);
		free(temp);
	}
}
void display(){
	node *temp;
	printf("ID\t\tName\t\tSemester\n");
	for(temp=header; temp!=NULL; temp=temp->link){
		printf("%d\t\t%s\t\t%d\n", temp->id,temp->name,temp->semester);
	}
}

void search(){
	int id;
	node *temp;
	printf("Enter the ID of student to be searched: ");
	scanf("%d",&id);
	
	for(temp=header; temp!=NULL; temp=temp->link){
		if(id == temp->id){
			printf("ID Name		Semester\n");
			printf("%d %s %d\n",temp->id,temp->name,temp->semester);
			return;
		}
	}
	printf("Student Record Not Found!!\n");
}

void menu(){
	int choice;
	
	printf("\nchoose: \n1 - Insert Student Record\n2 - Delete Student Record\n3 - Search Student Record\n4 - Display Student Records\nPress any other key to Exit!\n");
	
	scanf("%d",&choice);
	switch(choice){
		case 1:{
			insert();
			break;
		}
		case 2:{
			del();
			break;
		}
		case 3:{
			search();
			break;
		}
		case 4:{
			display();
			break;
		}
		default: {
			exit(0);
			break;
		}
	}
}

int main(){
	for( ; ; ){
		menu();
	}
	
	return 0;
}














