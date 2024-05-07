#include <iostream>
using namespace std;

static int c = 3;

int main() {
    int n, inneroption;

toan:
    cout << "Select the option: \n1) option 1\n2) option 2\n3) option 3\n4) Select again" << flush << endl;
    cout << "your option: ";
    cin >> n;
    cout << "your option is: " << n << "\nmove to option: " << n << endl;

    switch (n) {
        case 1:
        case 2:
        case 3:
            cout << n;
            cout << "Do you want to continue: \n" << "if yes type 1\n" << "if no type 0" << endl;
            cout << "your option is: "; 
            cin >> inneroption;
            if (inneroption == 0) {
                goto toan;
            }
            break;
        case 4:
            goto toan;
    }

    auto a = [&](int x) {
        c = c + 5;
        return x + c;
    };

    printf("\n%d\n%d\n%d\n%d\n%d\n%d", c, a(4), c, a(1), c, c);
    return 0;
}
