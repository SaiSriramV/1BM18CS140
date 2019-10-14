//done
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct node{
	char data[10];
	struct node *next;
}*Node;

Node create(){
	Node temp;
	temp=(Node)malloc(sizeof(Node));
	return temp;
}

Node insert(Node head,char ele[10]){
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

void display(Node head){
	int num,i;
	Node p;
	if(head==NULL)
		printf("No links\n");
	else{
		p=head;
		printf("Enter x: ");
		scanf("%d",&num);
		for(i=1;i<num;i++){
			p=p->next;
		}
		printf("Link is: %s\n",p->data);
	}
}

int main(){
	int n,i;
	char link[10];
	Node head=NULL;
	printf("Enter number of links: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter link%d: \n",i);
		scanf("%s",link);
		head=insert(head,link);
	}
	display(head);
	return 0;
}