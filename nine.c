//done
#include<stdio.h>
#define max 10

void push(int c1[],int *top,int ele){
	c1[*top]=ele;
	*top-=1;
}

int gcd(int a, int b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,(a%b));
}

int main(){
	int c1[max],c2[max],c3[max],n1,n2,n3,top,i,ele,val;
	printf("Enter height of three cylinders: ");
	scanf("%d %d %d",&n1,&n2,&n3);
	printf("Enter elements of first cylinder: ");
	top=n1;
	for(i=n1;i>0;i--){
		scanf("%d",&ele);
		push(c1,&top,ele);
	}
	printf("Enter elements of second cylinder: ");
	top=n2;
	for(i=n2;i>0;i--){
		scanf("%d",&ele);
		push(c2,&top,ele);
	}
	printf("Enter elements of third cylinder: ");
	top=n3;
	for(i=n3;i>0;i--){
		scanf("%d",&ele);
		push(c3,&top,ele);
	}
	val=gcd(n3,gcd(n1,n2));
	printf("\nFirst Cylinder: ");
	for(i=1;i<=val;i++){
		printf("%d ",c1[i]);
	}
	printf("\nSecond Cylinder: ");
	for(i=1;i<=val;i++){
		printf("%d ",c2[i]);
	}
	printf("\nThird Cylinder: ");
	for(i=1;i<=val;i++){
		printf("%d ",c3[i]);
	}
	return 0;
}