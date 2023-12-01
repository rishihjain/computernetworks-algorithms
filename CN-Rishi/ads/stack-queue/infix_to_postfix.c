#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

void push(char);
char pop();
int isEmpty();
void inToPost();
void print();
int precedence(char);
int space(char);


int main()
{
    printf("Enter the infix expression: ");
    gets(infix);
    inToPost();
    print();
    return 0;
}

void inToPost()
{
    int len = strlen(infix);
    int i, j = 0;
    char symbol, next;   // next is a variable to store the value of popped element temporarily
    for (i = 0; i < len; i++)
    {
        symbol = infix[i];
        if(!space(symbol))
        {
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while ((next = pop()) != '(')
                postfix[j++] = next;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                postfix[j++] = pop();  //element popped will be stored in the postfix array.
            push(symbol);
            break;
        default:
            postfix[j++] = symbol;
        }
        }
    }

    while (!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int precedence(char symbol)
{
    switch (symbol)
    {
    // Higher value means higher precedence
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0; 
    }
}
    
void print()
{
    int i = 0;
    printf("The equivalent postfix expression is: ");
    while (postfix[i])
    {
        printf("%c", postfix[i]);
        i++;
    }
    printf("\n");
}

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top = top+1;
    stack[top] = c;
}

char pop()
{
    char c;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    c = stack[top];
    top = top - 1;
    return c;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int space(char c)
{
   if(c==' ' || c=='\t')
   return 1;
   else 
   return 0;
}