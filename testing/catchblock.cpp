// C++ program to demonstate the use of catch all
// in exception handling.

#include <iostream>
using namespace std;

int main()
{
    char b = '5';
    char* x;
    x = &b;
	// try block
	try {

		// throw
		throw x;
	}

	// catch block
	catch (char* excp) {
		cout << "Caught " << *excp;
	}

    catch (int b) {
		cout << "Caught int " << b;
	}

	// catch all
	catch (...) {
		cout << "Default Exception\n";
	}
	return 0;
}
