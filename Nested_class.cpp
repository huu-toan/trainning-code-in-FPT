#include<iostream> 

using namespace std; 

/* start of Enclosing class declaration */
class Enclosing {
private:
    int x;
    
public:   
    /* start of Nested class declaration */
    class Nested {
    private:
        int y; // Private member
        
    public:
        Nested(int val) : y(val) {} // Constructor to initialize y
        
        // Getter method for y
        int getY() {
            return y;
        }
    }; // declaration Nested class ends here

    // EnclosingFun method to access Nested class member y
    void EnclosingFun(Nested *n) {
        cout << n->getY(); // Access y through public method
    }	 
}; // declaration Enclosing class ends here 

int main() {
    // Create an object of Enclosing class
    Enclosing obj;
    
    // Create an object of Nested class with value 10
    Enclosing::Nested nestedObj(10);
    
    // Pass the address of nestedObj to EnclosingFun method
    obj.EnclosingFun(&nestedObj);
    
    return 0;
} 
