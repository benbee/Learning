#include <iostream>

using namespace std;

class A {
public:
	A() {};
	A(A & a) {
		cout << "Copy constructor called" << endl;
	}
};

void Func(A a1){ }

int main()
{
	A a2;
	Func(a2);
	return 0;
}
