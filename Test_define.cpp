#include <iostream>
using namespace std;

union Color {
    unsigned int RED : 1;  
    unsigned int GREEN : 1; 
    unsigned int BLUE : 1;  
} color;

int main() {
    color.RED = 1; // Gán giá trị 1 cho RED

    if (color.RED) {
        cout << "The color is red. RED value: " << color.RED << endl;
    } else if (color.GREEN == 1) {
        cout << "The color is green." << endl;
    } else if (color.BLUE == 1) {
        cout << "The color is blue." << endl;
    }

    return 0;
}
