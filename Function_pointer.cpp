#include "stdio.h"

const int a = 10; 
const int b = 2;

int subtract(int a, int b)
{
    return (a - b);
}

void printresult(int (*pointerfunc)(int, int)) // Đặt kiểu của con trỏ hàm
{
    int result = pointerfunc(a, b); // Thêm đối số cho hàm printresult
    printf("giá trị test là: %p\n", (void *)pointerfunc); // Cú pháp in giá trị con trỏ hàm
    printf("Kết quả: %d\n", result); // In kết quả
}

int main()
{
    printresult(subtract); // Truyền hàm subtract vào hàm printresult
    return 0;
}
