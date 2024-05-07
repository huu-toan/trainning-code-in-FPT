#include"stdio.h"

void fun(int x) { 
  x = 20;
  printf("func: %p\n", x);
}
 
int main()
{
    int x = 10;
    printf("main: %p\n", &x);
    fun(x);
    printf("New value of x is %d", x);
    return 0;
}
//code 1 -> x = 10
