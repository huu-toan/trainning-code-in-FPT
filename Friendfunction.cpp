#include <iostream>
using namespace std;

class Test {
    private:
        int a;
        int b;
    public:
        void sum(int c, int d) {
            a = c;
            b = d;
        }
        friend class Test2;
};

class Test2 {
    public:
        void printtest(Test test) {
            cout << test.a << endl << test.b << endl;
        }
};

int main() {
    Test toan;
    toan.sum(3,4);

    Test2 quang;
    quang.printtest(toan);
    return 0;
}   