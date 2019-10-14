//done
#include <stdio.h>
#include<stdlib.h>

#define max 5

struct stack{
	int n;
	int st;
}s[max];

void push(int *top){
	int ele,sn;
	if(*top==(max-1))
		printf("Stack is full\n");
	else{
		printf("Enter element and stack number: ");
		scanf("%d %d",&ele,&sn);
		*top+=1;
		s[*top].n=ele;
		s[*top].st=sn;
	}
}

void pop(int *top){
	int i,j,sn;
	if(*top==-1)
		printf("Stack is empty\n");
	else{
		printf("Enter stack number: ");
		scanf("%d",&sn);
		for(i=*top;i>=0;i--){
			if(s[i].st==sn){
				printf("Deleted element: %d",s[i].n);
				for(j=i;j<*top;j++){
					s[j].n=s[j+1].n;
					s[j].st=s[j+1].st;
				}
				*top-=1;
				return;
			}
		}
		printf("Stack %d is empty\n",sn);
	}
}

void display(int *top){
	int i;
	if(*top==-1)
		printf("Stack is enpty\n");
	else{
		for(i=0;i<=*top;i++)
			printf("%d ",s[i].n);
	}
}

int main(){
	int top=-1,ch;
	do{
		printf("\n1)Push\n2)Pop\n3)Display\n4)Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: push(&top);
			        break;
			case 2: pop(&top);
			        break;
			case 3: display(&top);
			        break;
			case 4: break;
		}
	}while(ch!=4);
	return 0;
}