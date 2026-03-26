#include<stdio.h>
	void insert(int arr[] , int *size , int element , int position)
	{
		if(position < 0 || position > *size)
		{
			printf("Error: Invalid Position");
			return;
		}  
		for(int i = *size ; i>= position ; i--)
		{
			arr[i] = arr[i-1];
		}
		arr[position] = element;
		(*size)++;
	}
	void delete(int arr[], int *size , int position)
		{
			if(position < 0 || position >= *size)
			{
				printf("Error: Invalid Position");
				return;
			}
			for(int i = position; i<*size - 1; i++)
			{
				arr[i] = arr[i + 1];
			}
			(*size)--;
		}
	void display(int arr[], int size)
		{
			for(int i=0; i<size ; i++)
			{
				printf("%d\n ", arr[i]);
			}
			printf("\n");
		}
	int main()
	{
		int arr[100] = {10,20,30,40,50};
		int size = 5;
		printf("\nInitial array\n ");

		display(arr, size);
		int e_i= 25, e_p= 2;
		insert(arr , &size , e_i , e_p);
		printf("\nArray after inserting %d and position '%d' is  ",e_i,e_p);
		display(arr, size);
		int p_d = 3;
		delete(arr, &size, p_d);
		printf("\nArray after deletion of element at position '%d' is ",p_d);
		display(arr, size);
		return 0;
	}

