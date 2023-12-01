#include <stdio.h>
# define SIZE 100

void enqueue();
void dequeue();
void display();
int arr[SIZE];
int rear = - 1;
int front = - 1;

void enqueue()
{
    int value;
    if (rear == SIZE - 1)
       printf("Overflow \n");
    else
    {
        if (front == - 1)
      
        front = 0;
        printf("Element to be inserted in the Queue\n : ");
        scanf("%d", &value);
        rear = rear + 1;
        arr[rear] = value;
    }
} 

void dequeue()
{
    if (front == - 1 || front > rear)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", arr[front]);
        front = front + 1;
    }
} 
 
void display()
{
    
    if (front == - 1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (int i = front; i <= rear; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
}

int main()
    {
        int ch;
        while (1)
        {
            printf("1.Enqueue \n");
            printf("2.Dequeue \n");
            printf("3.Display the Queue\n");
            printf("4.Exit\n");
            printf("Enter your choice of operations : ");
            scanf("%d", &ch);
            switch (ch)
            {
                case 1:
                enqueue();
                break;
                case 2:
                dequeue();
                break;
                case 3:
                display();
                break;
                case 4:
                exit(0);
                default:
                printf("Incorrect choice \n");
            } 
        } 
    } 