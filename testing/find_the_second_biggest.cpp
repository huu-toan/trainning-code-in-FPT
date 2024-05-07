#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {

    set<int> second = {};

    int k;
    cout << "insert array size: ";
    cin >> k;
    int array[k];

    for (int i = 0; i < k; i++){
        cout << "Member[" << i << "]: ";
        cin >> array[i];
    }

    cout << "array: ";

    for (int i = 0; i < k; i++){
        cout << array[i] << " ";
    }

    cout << endl;
    for (int i = 0; i < k; i++)
    {
        second.insert(array[i]);
        cout << "insert value array[" << i << "] = " << array[i] << endl; 
    }

    cout << "Val in array: ";
    for(int x : array){
        cout << x << ' ';
    }

    cout << "\nVal in set: ";
    for(int x : second){
        cout << x << ' ';
    }
    

    if (second.size() < 2) {
        cout << "\nNo second biggest val" << endl;
    } else {
        second = set<int>(second.rbegin(), second.rend());

        set<int>::iterator ptr = second.end();
        advance(ptr, -2);

        cout << "\nsecond biggest val: " << *ptr << endl;
    }

    return 0;
}
