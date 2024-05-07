#include <iostream>
#include <string>
using namespace std;

int main(){
    char a[6] = {'2', '8', 't', 'e', 'c', 'h'};
    for(char x : a){
        a[1] = '1'; // -> output: 21tech
    }
    cout << "Sau khi thay doi : \n";
    for(char x : a){
        cout << x << ' ';
    }
    return 0;
}