#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top = -1;

int isFull()
{
    if(top == MAX-1)
    return 1;
    else 
    return 0;
}

int isEmpty()
{
    if(top == -1)
    return 1;
    else 
    return 0;
}

int push()
{
    int data;
  if(isFull())
  {
    printf("STACK OVERFLOW");
    return;
  } 
  top = top+1;
  stack_arr[top] = data;
  return 0;
}

int pop()
{
    int value;
    if(isEmpty())
    {
        printf("STACK UNDERFLOW");
        exit(1);
    }
    value = stack_arr[top] ;
    top = top-1;
    return value;
}

int peek()                          
{
    if(isEmpty())
    {
        printf("STACK UNDERFLOW");
        exit(1);
    }
    return stack_arr[top];
}

void print()
{
    int i;
    if(top == -1)
    {
        printf("STACK UNDERFLOW");
        exit(1);
    }
    for(i=0; i<=top; i++)
    {
        printf("%d",stack_arr[i]);
        printf("\n");
    }
}

int main()
{
    int choice , data;
    while(1)
    {
        printf("\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. Print the top element\n");
        printf("4. Print all the elemnts of the stack\n");
        printf("5. QUIT\n");
        printf("Please enter your choice : ");
        scanf("%d", &choice);

    switch(choice){
        case 1:
        printf("Enter the element to be pushed: ");
        scanf("%d",&data);
        push(data);
        break;

        case 2:
        data = pop();
        printf("Deleted element is %d\n", data);
        break;

        case 3:
        printf("The topmost element of the stack is %d\n", peek());
        break;

        case 4:
        printf("The elements of the arrays are :\n");
        print();
        break;

        case 5:
        exit(1);

        default : 
        printf("Wrong Choice");

    }
    }
return 0;  
}
