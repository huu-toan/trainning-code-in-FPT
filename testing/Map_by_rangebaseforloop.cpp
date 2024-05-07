#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    map<string, int> mp;
    mp.insert(make_pair("a", 2)); // ok
    mp.insert(make_pair("be", 4)); // ok
    mp.insert(make_pair("k", 5)); // ok
    for(pair <string,int> x : mp){
         cout << x.first << endl;
    }
    for(pair<string, int> it : mp){
        cout << "key = " << it.first << ", value = " << it.second << endl;
    }
    map<string,int>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++){
        cout << "key = " << (*it).first << ", value = " << (*it).second << endl; 
    }
    map<string,int>::reverse_iterator it1;
    for(it1 = mp.rbegin(); it1 != mp.rend(); it1++){
        cout << "key = " << (*it1).first << ", value = " << (*it1).second << endl; 
    }
}