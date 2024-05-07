#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    map<int, int> mp;
    mp.insert(make_pair(1, 2)); // ok
    mp.insert(make_pair(1, 5)); // not ok
    mp.insert(make_pair(2, 4)); // ok
    mp.insert(make_pair(2, 5)); // not ok
    mp.insert(make_pair(2, 1)); // not ok
    mp.insert(make_pair(3, 1)); // ok
    mp[5] = 10; // them moi
    mp[1] = 100; // thay doi value cua key 1 thanh 100
    cout << mp.size() << endl;
    cout << "Value tuong ung cua key 1 : " << mp[1] << endl; // 100
    cout << "Value tuong ung cua key 5 : " << mp[5] << endl; // 10
}