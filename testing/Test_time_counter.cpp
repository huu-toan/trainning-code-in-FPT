#include <iostream>
#include <chrono>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace chrono;


void Time_Count(int n) {
    int second = 0;
    auto start = high_resolution_clock::now();
    while (second < n) {
        auto end = high_resolution_clock::now();
        cout << "Clock time: " << duration_cast<seconds>(end - start).count() << flush << '\r';
        Sleep(1000);
        second++;
    }
}
int main() {
    
    cout << getch() << endl;
    return 0;
}
