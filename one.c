/*done*/
#include<stdio.h>
#define max 5

void insert(int s[],int *top)
{
	int item;
	if(*top==(max-1))
		printf("Stack full\n");
	else{
		printf("Element: ");
		scanf("%d",&item);
		s[++(*top)]=item;
	}
}

void display(int s[],int *top)
{
	int i,j=0,k,least;
	if(*top==-1)
		printf("Stack empty");
	else
	{
		least=s[*top];
		for(i=0;i<=*top;i++){
			if(least>s[i])
				least=s[i];
		}
		for(i=0;i<=*top;i++){
			if(s[i]==least){
				for(k=i;k>j;k--){
					s[k]=s[k-1];
				}
				s[j]=least;
				j++;
			}
		}
		for(i=*top;i>=0;i--){
			printf("%d ",s[i]);
		}
	}
}

int main()
{
	int ch,s[max],top=-1;
	do
	{
		printf("\n1)Insert\n2)Display\n3)Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert(s,&top);
			       break;
			case 2:display(s,&top);
			        break;
			default: printf("Invalid choice");
		}
	}while(ch!=3);
	return 0;
}
