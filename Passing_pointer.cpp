// C program to return multiple values from a function

#include <stdio.h>

// Function to calculate sum and product of two numbers
void calcSumAndProduct(int* sum, int* prod)
{
    int x = 7;
    int y = 20;
	*sum = x + y;
	*prod = x * y;
}

int main()
{
	int sum, prod;
	// calling the function to calculate sum and product
	calcSumAndProduct(&sum, &prod);

	// printing the sum and product returned from function
	printf("Sum is: %d \nProduct is: %d\n", sum, prod);

	return 0;
}
