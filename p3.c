#include<stdio.h>
#include<stdlib.h>
#define max 4
    int top = -1, stack[max];
    void push();
    void pop();
    void peek();
    void display();

int main(void)
{
    int choice;
    while(1)
    {   
        printf("\nStack Operations:");
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit");
        printf("\nEnter your choice: ");
        scanf(" %d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}

void push()
{
    int x;
    if(top == max-1)
    {
        printf("Stack overflow");
    }
    else
    {
        printf("Enter the item to be pushed: ");
        scanf("%d",&x);
        top = top +1;
        stack[top] = x;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        printf("Popped item is %d",stack[top]);
        top = top -1;
    }
}

void peek()
{
    if(top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Top item is %d",stack[top]);
    }
}

void display()
{
    int i;
    if(top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Stack elements are: ");
        for(i=top; i>=0; i--)
        {
            printf("%d ",stack[i]);
        }
    }
}