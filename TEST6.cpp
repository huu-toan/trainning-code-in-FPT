#include <stdio.h> 

#define thunghiem 32
int foo (int a, int b) {
    int c = 10;
}

int main(int argr, char* argb[]) 
{ 
    int a = 5, b = 6, p;
    foo(a,b);
    printf("add: %p", &foo);

    int *k, *j;
    k = &a;
    j = &b;
    int sum;
    printf("\naddsum: %p, valsum: %d\n", k, *k);
    *k += 1;
    printf("\naddsum: %p, valsum: %d\n", k, *k);
    return 0; 
} 


