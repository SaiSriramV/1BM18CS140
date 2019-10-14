//done
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define SIZE 10
int top=-1;

struct student
{
    char student_usn[10];
    char student_name[15];
    char number[10];
}s[SIZE];

void push(char usn[],char name[],char num[])
{
    if (top==(SIZE-1))
        printf("Stack Full\n\n");
    else
    {
        top=top+1;
        strcpy(s[top].student_usn,usn);
        strcpy(s[top].student_name,name);
        strcpy(s[top].number,num);
    }
}

void pop()
{
    if (top==-1)
        printf("Stack Empty\n\n");
    else
    {
    	printf("\nStudent Exited: \n");
    	printf("Name: %s\nUSN: %s\nNumber: %s\n",s[top].student_name,s[top].student_usn,s[top].number);
    	top-=1;
    }
}

void print()
{
    if(top==-1)
        printf("No Student entered\n\n");
    else
    {
         for(int i=0;i<=top;i++)
         {
              printf("Student %d: \n",i+1);
              printf("Student USN: %s\n",s[i].student_usn);
              printf("Name: %s\n",s[i].student_name);
              printf("Number: %s\n\n",s[i].number);
         }

    }
}

int main()
{
    int choice;
    char usn[20],name[20],num[10];
    do
    {
        printf("\n1)Push\n2)Pop\n3)Print\n4)Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter usn,name and number of the student: ");
                   scanf("%s %s %s",usn,name,num);
                   push(usn,name,num);
                   break;
            case 2:pop();
                   break;
            case 3:print();
                   break;
            case 4:break;
            default:printf("Invalid Choice\n");
        }
    }while(choice!=4);
    return 0;
}
