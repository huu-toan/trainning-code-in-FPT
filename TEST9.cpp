#include <stdio.h>

#define PRINT(i, limit) do { \
                            if (i++ < limit) \
                            { \
                                printf("GeeksQuiz\n"); \
                                continue; \
                            } \
                        } while(0)

int main()
{
    int a = 10;
    int &p = a;
    p =20;
    a = 3;
    printf("%d\n%p\n", p, &a);

    int i = 0;
    PRINT(i, 3);
    return 0;
}

