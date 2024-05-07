#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v = {100, 200, 300, 400, 500};
    vector<int>::iterator it = v.begin();
    it += 3;
    cout << "Chi so cua phan tu ma it dang tro toi : " << it - v.begin() << endl; // -> output: 3
    cout << "Chi so cua phan tu ma it dang tro toi : " << distance(v.begin()+2, it) << endl; // -> output: 1
}

