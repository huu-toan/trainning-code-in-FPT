#include <iostream>
using namespace std;

const int a = 15;
const int b = 2;
// pointer function
int multiply(int s, int k) { 
	int sum = a-k;
	int sub = a+s;
	return sum*sub; 
	}

//passing function as parameter
void printline(int(*func)(int a,int b)){
	printf("thử nghiệm: %p\n", func);
}
// Driver Code
int main()
{
	//pointer to constant
	int high = 100;
	int low = 66;
	int* score = &high; // =(*(&high) = high)
	*score = 30;
	cout << high << endl;
	cout << *score << "\n"; // -> 100
	score = &low; // =(*(&low) = low)
	cout << *score << "\n"; // -> 66

	//constant pointer
	int a{ 90 };
    int b{ 50 };
    int* const ptr{ &a };
    cout << *ptr << "\n";
    cout << ptr << "\n";
	*ptr = 56;
	cout << *ptr << "\n";
    cout << ptr << "\n";
	a = 40;
	cout << *ptr << "\n";
    cout << ptr << "\n";

	//function pointer
	int (*funcptr)(int,int);
	funcptr = multiply;
	int prod = funcptr(15, 2);
    printf("The value of the product is: %p, %p, %d, %p, %d, %d\n", *(&funcptr), funcptr, prod,&multiply, multiply, *funcptr);

	//Passing a function pointer as a parameter
	printline(multiply);
	return 0;
}
