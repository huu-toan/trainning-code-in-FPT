#include "stdio.h"

static int c = 3;

int main() {
    auto a = [&](int x) {
        c = c + 1;
        return x + c;
    };

    printf("\n%d\n%d\n%d\n%d", c, a(2), c, c);
    return 0;
}
