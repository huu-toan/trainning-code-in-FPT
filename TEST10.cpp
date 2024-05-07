// C program to demonstrate structure pointer
#include <stdio.h>

#if X == 3
    #define Y 3
#else
    #define Y 5
#endif

struct point {
    int value;
};
 
int main()
{
 
    struct point s;
   
    // Initialization of the structure pointer
    struct point* ptr = &s;
    
    printf("%d", Y);

    return 0;
}
//In the above code s is an instance of struct point and ptr is the struct pointer 
//because it is storing the address of struct point. 