#include <stdio.h>
// pointer increment and decrement
//pointers are incremented and decremented by the size of the data type they point to 
int main()
{
	int a = 22;
	int *p = &a;
	printf("p = %u, %d\n", &a, a); // p = 6422288 -> float cũng vậy
	(*p)++;
	printf("p++ = %u, %d\n", p, a); //p++ = 6422292 +4 // 4 bytes
	p--;
	printf("p-- = %u, %d\n", p, a); //p-- = 6422288	 -4 // restored to original value

    int b = 10;
    printf("valb: %d, b = %u\n", b,&b);
    b++;
    printf("valb++: %d,b++ = %u\n", b,&b);

	char c = 'a';
	char *r = &c;
	printf("r = %u\n", r); //r = 6422283
	r++;
	printf("r++ = %u\n", r); //r++ = 6422284	 +1 // 1 byte
	r--;
	printf("r-- = %u\n", r); //r-- = 6422283	 -1 // restored to original value

	return 0;
}
