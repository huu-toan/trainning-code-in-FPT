#include <iostream>
#include <string>

using namespace std;

class Person {
private:
	string name = "toan";
	int age = 5;
public:
	Person(string name, int age) {
        cout << name;
	}
	void setNameAge(string name, int age) {
        this->name = name;
        this->age = age;
	}
	string getName() {
	
	}
	int getAge() {
	return age;
	}
    ~Person () {}
};

int main() {
Person person("John Doe", 30);

cout << "Name: " << person.getName() << endl;
cout << "Age: " << person.getAge() << endl;

person.setNameAge("Jane Doe", 33);

cout << "Name: " << person.getName() << endl;
cout << "Age: " << person.getAge() << endl;

return 0;
}
