/*done*/
#include<stdio.h>
#define max 20

void push(char s[],char val,int *top)
{
	*top+=1;
	s[*top]=val;
}

char pop(char s[],int *top)
{
	char val;
	val=s[*top];
	*top-=1;
	return val;
}

int main(){
	char s[max],exp[max];
	int top=-1,i=0;
	printf("Enter the expression: ");
	scanf("%s",exp);
	while(exp[i]!='\0'){
		if(exp[i]=='{' || exp[i]=='[' ||exp[i]=='(')
			push(s,exp[i],&top);
		else if(exp[i]=='}' || exp[i]==']' || exp[i]==')'){
			if(exp[i]=='}' && s[top]!='[' && s[top]!='(')
				pop(s,&top);
			else if(exp[i]==']' && s[top]!='{' && s[top]!='(')
				pop(s,&top);
			else if(exp[i]==')' && s[top]!='[' && s[top]!='{')
				pop(s,&top);
		}
		else{
			printf("Invalid");
			return 0;
		}
		i++;
	}
	if(top==-1)
		printf("YES");
	else
		printf("NO");
	return 0;
}