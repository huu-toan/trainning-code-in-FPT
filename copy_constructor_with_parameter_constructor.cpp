#include <iostream>
#include <cstring> // Thêm thư viện này để sử dụng hàm strcpy
using namespace std;

// Class definition
class student {
	int rno;
	char name[50];
	double fee;

public:
	// Parameterized constructor
	student(int no, char n[], double f) {
		rno = no;
		strcpy(name, n);
		fee = f;
	}

	// Copy constructor
	student(const student& t) {
		rno = t.rno;
		strcpy(name, t.name);
		fee = t.fee;
	}

	// Display function
	void display() {
		cout << endl << rno << "\t" << name << "\t" << fee;
	}
};

int main() {
	// Khởi tạo đối tượng s
	student s(1001, "Manjeet", 10000);
	cout << "Original object: ";
	s.display();

	// Gọi copy constructor để tạo đối tượng manjeet từ s
	student manjeet(s);
	cout << "\nCopied object: ";
	manjeet.display();

	return 0;
}
