#include <MyLib.hpp>
#include <iostream>
#include <string>
using namespace std;

struct Bigger {
	char sz[20];
	Bigger( char* s ) { strcpy(sz,s); }
};

int main() {
	int i = 42;
	cout << "i = " << i << ": " << bit_string(i) << endl;
	double x = 3.14159;
	cout << "x = " << x << ": " << bit_string(x) << endl;
	Bigger b("Hello");
	cout << "b = " << b.sz << ": " << bit_string(b) << endl;

}