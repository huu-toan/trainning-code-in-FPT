#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v = {28, 100, 30, 20, 15};
    vector<int>::iterator it1 = v.begin();
    cout << "v[0] = " << &it1 << " " << &v[0] <<  endl;
    vector<int>::reverse_iterator it2 = v.rbegin();
    cout << "v[4] = " << &it2 << endl;
    return 0;
}