#include <iostream>
using namespace std;

class Test {
    public:
    int n = 3;
};

void printn (int n){
    cout << "Test" << n;
}

int main () {
    Test Test;
    printn (Test.n);
    return 0;
}