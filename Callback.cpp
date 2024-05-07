#include <iostream>
using namespace std;

// callback function
int foo(char c) { return (int)c; }

int thu(int a) { return (a >= 5); }

// another function that is taking callback
void printASCIIcode(char c, int (*func_ptr)(char))
{
    int ascii = func_ptr(c);
    cout << "ASCII code of " << c << " is: " << ascii;
}

// driver code
int main()
{
    int arr[] = {6, 7, 8, 9};
    for (int i = 0; i < 4; ++i)
    {
        int k = thu(arr[i]);
        cout << "thu: " << k << endl;
    }
    printASCIIcode('a', &foo);
    return 0;
}
