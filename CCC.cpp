#include <bits/stdc++.h>
using namespace std;
#define pi 3.14
#define concat(a, b) a##b
#define tokenpaster(n) printf("\ngiá trị macro = %d", test##n)
const int mm = 34;

//test enum
enum HOC {toan, tuan, chien};

typedef HOC toanlanhat; 

string toanlanhatToString(toanlanhat value) {
    switch (value) {
        case toan: return "toan";
        case tuan: return "tuan";
        case chien: return "chien";
        default: return "unknown";
    }
}

string enumToString(HOC value) {
    switch (value) {
        case toan: return "toan";
        case tuan: return "tuan";
        case chien: return "chien";
        default: return "unknown";
    }
}

//test union
union Data {
    int i;
    float f;
    char str[20];
};

/*struct Test
{
    int thutu;
    int diem;
    //unsigned int gg:7;
};*/
const int a10 = 5;

//test linked list

struct node 
{
    int data;
    struct node *next;
};



int main() {
    toanlanhat toan1; // Use the typedef
    enum HOC hocsinh2;
    hocsinh2 = chien;

    union Data data;

    printf("Kích thước của union: %ld bytes\n", sizeof(union Data));

    // Gán giá trị cho các thành phần
    data.i = 10;
    printf("Gia tri cua data.i: %d\n", data.i);

    data.f = 3.14;
    printf("Gia tri cua data.f: %f\n", data.f);

    // Gán giá trị cho thành phần khác
    strcpy(data.str, "Hello, C!");
    printf("Gia tri cua data.str: %s\n", data.str);

    float test = 12.3425;
    float thunghiem = test/1;
    cout << int(thunghiem) << "\r" << pi << endl;
    printf("%f", test);

    bool a = true;
    bool b = false;
    
    bool resultand = a||b;

    cout << bool(a^b) << endl;
    Laplai:
    int thuu = 5;
    thuu--;
    long double ab;
    cout << sizeof(ab) << endl;

    {
        int a = 5;
        {
            int a = 6;
        //    cout << a << endl;
        }
      //  cout << a << endl;
    }

    int puts(const char *s);
    //putchar('B');
    //int putch('A');
    /*if(thuu < 1)
    {
        goto Laplai; 
    }
    cout << thuu;*/

    //test while
    int i = 5;
    printf("test while\n");
    while(i > 1) 
    {
        printf("%d\n", i);
        i--;
    }

    //test for
    printf("test for\n");
    for(i = 5; i > 1; i--) 
    {
        printf("%d\n", i);
    }

    //test do-while
    i = 5;
    printf("test do-while\n");
    do
    {
        printf("%d\n", i);
        --i;
        continue;
        i++;
    } while (i > 1);

    //Mảng con trỏ
    /*int thumang[10];
    int *Pi = thumang;
    for(int i = 0; i < 9; i++)
    {
        *(Pi+i) = 1;
        printf("Phần tử thứ %d của mảng: %d\n", i, *(Pi+i));
    }
    // in ra
    /*printf("full mảng");
    for(int i = 0; i < 9; i++)
    {
        printf("%d ", *(Pi+i));
    }

    //Test struct
    Test test(1,1);
    Test *test_ptr = &test;
    cout << (*test_ptr).diem << endl << test_ptr->diem << endl; //<< test.diem;
    */
    const int a10 = 3;

   //test mảng động
   int *p;
   int ann = 0;
   p=(int*)malloc(10 *sizeof(int*));
   for (int i = 0; i < 10; i++)
   {
    *(p+i) = ann++;
   }
   for (int i = 0; i < 10; i++)
   {
    printf("%d", *(p+i));
   }

    printf("\nsize of bool: %d\n", sizeof(bool));
   //test linked list

    printf("dia chi cua ann: %d \n", &ann);
    printf("địa chỉ const: %d\n", &mm);

    int longg;
    int lingg;
    printf("Thu uninitalized: %d\n", lingg);

    int xy = 30;
    printf("%d", concat(x,y));

    int test30 = 1;
    tokenpaster(30);
    printf("\na10: %d", a10);
    return 0;
}

// BuG của memory
int func1 (){
    int a = 4; //trên frame 2 có a = 4
    int *p = new int(12); //p và địa chỉ giá trị int(12) sẽ được lưu trên 
    //->frame 2 và giá trị 12 lưu trên heap 
    return a; // sau khi giá trị của a được trả về 4 thì xóa frame 2 -> xóa địa chỉ của 12 trên stack
    // tuy nhiên giá trị 12 thì lại vẫn được lưu trong heap mà không biến nào có quyền truy cập 
    // -> tốn bộ nhớ -> memory leak -> và khi bị dùng với recursion overflow thì rất nguy hiểm -> ko có cách
    // nào để free memory -> vậy nên trước khi frame 2 bị xóa thì ta phải xóa pointer bằng delete
}
int main() {
    int c = func1() //gọi hàm func -> chạy hàm func và đưa biến c vào trong stack
    return 0;
}

// lvalues_and_rvalues2.cpp
int main()
{
    int i, j, *p;

    // Correct usage: the variable i is an lvalue and the literal 7 is a prvalue.
    i = 7;

    // Incorrect usage: The left operand must be an lvalue (C2106).`j * 4` is a prvalue.
    7 = i; // C2106
    j * 4 = 7; // C2106

    // Correct usage: the dereferenced pointer is an lvalue.
    *p = i;

    // Correct usage: the conditional operator returns an lvalue.
    ((i < 3) ? i : j) = 7;

    // Incorrect usage: the constant ci is a non-modifiable lvalue (C3892).
    const int ci = 7;
    ci = 9; // C3892
}