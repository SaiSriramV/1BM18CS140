//done
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char data[10];
	struct node *next;
}*Node;

Node create(){
	Node p;
	p=(Node)malloc(sizeof(Node));
	return p;
}

Node insert(Node head,char ele[]){
	Node p,q;
	p=create();
	strcpy(p->data,ele);
	p->next=NULL;
	if(head==NULL)
		return p;
	else{
		q=head;
		while(q->next!=NULL)
			q=q->next;
		q->next=p;
		return head;
	}
}

Node delete(Node head){
	Node p,prev;
	char ele[10];
	printf("Enter the element: ");
	scanf("%s",ele);
	if(head==NULL)
		return head;
	p=head;
	if(strcmp(p->data,ele)==0)
		head=head->next;
	else{
		while(p->next!=NULL){
			prev=p;
			p=p->next;
			if(strcmp(p->data,ele)==0){
				prev->next=p->next;
				free(p);
				return head;
			}
		}
		printf("Invalid element\n");
	}
	return head;
}

void display(Node head){
	Node p;
	p=head;
	if(head==NULL)
		printf("List is empty\n");
	else{
		printf("Elements: ");
		while(p!=NULL){
			printf("%s ",p->data);
			p=p->next;
		}
	}
	printf("\n");
}

int main(){
	Node head;
	char ele[10];
	int ch;
	head=NULL;
	do{
		printf("\n1)Insert\n2)Delete\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter the data: ");
			        scanf("%s",ele);
					head=insert(head,ele);
			        display(head);
			        break;
			case 2: head=delete(head);
			        display(head);
			        break;
			case 3: break;
		}
	}while(ch!=3);
	return 0;
}