#include<stdio.h>

int RSum(int n)//the int Rsum(int n ) is a recursive function which takes an integer n as input and returns the integer of the sum of the first n natural numbers. --- IGNORE ---
{
	int k;
	if(n == 0)
	{
		return 0;
	}
	else
	{
		k= n + RSum(n-1);
		return k;
	}
}
int main()
{
	int n = 5;
	int sum = RSum(n);
	printf("Sum of First %d Natural Numbers: %d",n,sum);
	return 0;
}
	
		
