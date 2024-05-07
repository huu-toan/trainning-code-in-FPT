#include "stdio.h"

// Global variable
int number;

// Function declaration
int& retByRef(){ //-> khai báo kiểu int& này giúp ta có thể sử dụng retByRef này như 
//một biến và gán thẳng number bằng 1 giá trị khác
    return number;
}

int main(){
    // Function call for return by reference
    retByRef() = 2; 
    
    // print number
    printf("num: %d", number);
    printf("\naddress: %p", retByRef);
    return 0;
}