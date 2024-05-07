#include <stdio.h> 

#define thunghiem 32

// Inline function in C 
inline int foo() 
{ 
    return 2; 
} 

// Driver code 
int main() 
{ 
  
    int ret; 
  
    // inline function call 
    ret = foo(); 

    #ifndef thunghiem
        printf("Output is: %d\n", ret); 
    #endif
    return 0; 
} 
