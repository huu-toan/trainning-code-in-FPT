// C++ program without any compilation error to demonstrate 
// that member methods of local class can only access static 
// and enum variables of the enclosing function 
#include <iostream> 
using namespace std; 

void fun() 
{ 
    // member của local class chỉ có thể truy cập biến static và enum
	static int x; //phải khai báo x là static bởi khai báo int x thôi thì method không
    // thể truy cập được
	enum { i = 1, j = 2 }; // tương tự phải khai báo i là enum 

	// Local class 
	class Test { 
	public: 
        int toan;
		static void method() //chỉ có thể chứa static function mà không thể chứa static val
        // nếu khai báo static int x trong class thì sẽ error
		{ 
			cout << "x = " << x 
				<< endl; // fine as x is static 
			cout << "i = " << i 
				<< endl; // fine as i is enum 
		} 
	}; 

	Test t; 
	t.method(); 
} 

int main() 
{ 
	fun(); //khởi tạo mặc định theo static x = 0 còn i theo enum thì = 1
	return 0; 
}
