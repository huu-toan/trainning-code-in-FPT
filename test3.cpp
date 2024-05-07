#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int p = 5;
    int *y = &x;
    int *z = &x;
    printf("addx: %p, sizeofy: %d, addy: %p, addz: %p", (void*)&x, sizeof(y), (void*)&y, (void*)&z);
    int sum;
    sum = *y + *z + 10;
    printf("\nsum: %d, add: %p", sum, (void*)&sum);
    int test = 10;
    int *px, **ppx;
    px = &test;
    ppx = &px;
    printf("\nvaltest: %d\naddtest: %p\nvalpx: %d\nvalppx: %d\naddpx: %p\naddppx: \n", test, &test, px, *ppx, *(&px));

    return 0;
}
