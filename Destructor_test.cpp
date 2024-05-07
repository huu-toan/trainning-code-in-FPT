#include <iostream>

using namespace std;

class base {
public:
    base()	 
    { cout << "Constructing base\n"; }
    virtual ~base()
    { cout << "Destructing base\n"; }	 
};

class derived1 : public base {
public:
    derived1()	 
    { cout << "Constructing derived1\n"; }
    ~derived1()
    { cout << "Destructing derived1\n"; }
};

class derived2 : public base {
public:
    derived2()	 
    { cout << "Constructing derived2\n"; }
    ~derived2()
    { cout << "Destructing derived2\n"; }
};

int main()
{
    derived2 *d = new derived2();
    base *b = d; // Chuyển đổi từ derived2* sang base*
    base **ptr_to_ptr = &b; // Gán con trỏ cấp 1 cho con trỏ cấp 2

    delete b; // Xóa đối tượng chỉ được giữ bởi con trỏ cấp 1

    getchar();
    return 0;
}

