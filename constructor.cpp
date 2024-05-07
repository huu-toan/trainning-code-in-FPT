#include <iostream>
using namespace std;

class construct {
public:
	int a, b;

	// Default Constructor
	construct()
	{
		a = 10;
		b = 20;
	}

    void printlin() {
        cout << "a: " << this->a << endl << "b: " << this->b;
    }
};

int main()
{
	construct c;
    c.printlin();
	return 1;
}
