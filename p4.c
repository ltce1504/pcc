#include<stdio.h>
#include<stdlib.h>
# define Max 5
    int queue[Max],F=-1,R=-1;// queue is an array of integers with a maximum size of Max, F is the front index of the queue initialized to -1, and R is the rear index of the queue also initialized to -1. --- IGNORE ---
    //functions for queue operations; function declarations for insert, delete, and display operations on the queue. --- IGNORE ---
    void insert()
        {
            int num;
            printf("\n Enter the element to be inserted ");
            scanf("%d",&num);
            if(R==Max -1)
                {
                    printf("\n Overflow");
                }
            else if(F==-1 && R==-1)
                {
                    F=R=0;
                }
            else
                {
                    R=R+1;
                }
            queue[R]=num;
            printf("\n Element Inserted");
        }
    void delete()
        {
            int num;
            if(F==-1||F>R)
                {
                    printf("\nUnderflow");
                }
            else
                {
                    num = queue[F];
                    printf("The deleted element is: %d",num);
                }
            F = F+1;
        }
    void display()
        {
            printf("\nQueue:");
                for(int i=F; i<=R;i++)
                    {
                        printf("\n %d",queue[i]);
                    }
        }
    int main()
        {
            int choice;
            while(1)
                {
                    printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
                    printf("\nEnter your choice: ");
                    scanf("%d",&choice);
                    switch(choice)
                        {
                            case 1: insert();
                            break;
                            case 2:delete();
                            break;
                            case 3:display();
                            break;
                            case 4 :exit(0);
                            break;

                            default:printf("\n Invalid choice");
                        }
                }
        }

/*basic operation of queue
1. Insert: This operation adds an element to the rear of the queue. If the rear index (R) reaches the maximum size (Max - 1), it indicates that the queue is full, and an overflow message is displayed.
2. Delete: This operation removes an element from the front of the queue. If the front index (F) is -1 or exceeds the rear index (R), it indicates that the queue is empty, and an underflow message is displayed. Otherwise, the element at the front is removed, and the front index is incremented.
3. Display: This operation prints the elements in the queue from the front index (F)*/

/*Alogithm of main function
step 1: Initialize the queue array and front and rear indices to -1.
step 2: Display a menu with options for insert, delete, display, and exit.
step 3: Read the user's choice.
step 4: Based on the user's choice, call the appropriate function (insert, delete, display).
step 5: If the user chooses exit, terminate the program.
step 6: If an invalid choice is entered, display an error message.
step 7: Repeat steps 2-6 until the user chooses to exit.

algorithm of insert
step 1: Read the element to be inserted.
step 2: Check if the rear index (R) is equal to Max - 1. If so, display an overflow message and return.
step 3: If both front (F) and rear (R) are -1, set both F and R to 0.
step 4: Otherwise, increment the rear index (R).
step 5: Insert the element at the position indicated by the rear index (R).
step 6: Display a success message indicating that the element has been inserted.

algorithm for delete
step 1: Check if the front index (F) is -1 or exceeds the rear index (R). If so, display an underflow message and return.
step 2: Store the element at the front index (F) in a temporary variable.
step 3: Increment the front index (F).
step 4: Display the deleted element. */
