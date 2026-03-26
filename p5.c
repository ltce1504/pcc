#include<stdio.h>
#include<stdlib.h>
#define max 5

int queue[max], F = -1, R = -1;

// Insert -> insert an element into the circular queue
void insert() {
    int num;
    if ((F == 0 && R == max - 1) || (R + 1 == F))
        {
            printf("\n Overflow");
            return;
        }
    else{
        printf("\n Enter the element to be inserted: ");
        scanf("%d", &num);
    
    if (F == -1 && R == -1) {
        F = R = 0;
    } else if (R == max - 1 && F != 0) {
        R = 0;
    } else {
        R++;//or r =r+1
    }}
    queue[R] = num;
}

// Delete
void delete() {
    int val;
    if (F == -1) {
        printf("\n Underflow");
    } else {
        val = queue[F];
        printf("\n Element %d deleted", val);
        if (F == R) {
            F = R = -1;
        } else {
            if (F == max - 1)
                F = 0;
            else
                F++;
        }
    }
}

// Display
void display() {
    printf("\nQueue: ");
    if (F == -1) 
    {
        printf("\n Queue is empty..");
    } else 
    {
        if (F <= R) 
        {
            for (int i = F; i <= R; i++)
                printf("%d ", queue[i]);
        } else 
        {
            // Print from Front to end of array
            for (int i = F; i < max; i++)
                printf("%d ", queue[i]);
            // Print from start of array to Rear
            for (int i = 0; i <= R; i++)
                printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function
void main() {
    int choice;
    while (1) {
        printf("\n Circular Queue Operations \n1. Insert \n2. Delete \n3. Display \n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: printf("\nExiting, Goodbye!"); exit(0);
            default: printf("\nInvalid choice");
        }
    }
}