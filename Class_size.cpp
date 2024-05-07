#include <xmmintrin.h>
#include <stdio.h>

class TestClass1 {
  __m128i vect;
};

class TestClass2 {
  char buf[5];
  int buf2[8];
};

class TestClass3 {
  char buf[8];
  __m128i vect;
  char buf2[8];
};

class TestClass4 {
  char buf[8];
  char buf2[8];
  __m128i vect;
};


TestClass1 *ptr1;
TestClass2 *ptr2;
TestClass3 *ptr3;
TestClass4 *ptr4;
int main() {
  ptr1 = new TestClass1();
  ptr2 = new TestClass2();
  ptr3 = new TestClass3();
  ptr4 = new TestClass4();
  printf("sizeof TestClass1 is: %lu\t TestClass2 is: %lu\t TestClass3 is: %lu\t TestClass4 is: %lu\n", sizeof(*ptr1), sizeof(*ptr2), sizeof(*ptr3), sizeof(*ptr4));
  return 0;
}