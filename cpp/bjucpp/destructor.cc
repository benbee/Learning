#include <iostream>
using namespace std;

class Ctest {
public:
    ~Ctest() { cout << "Destructor called" << endl; }
};

int main(int argc, char *argv[])
{
    // Ctest array[2];
	Ctest *pTest;
	pTest = new Ctest;
	delete pTest;

	pTest = new Ctest[3];
	delete []pTest;				// do not forgget [] before ptr
	
	cout << "End Main" << endl;
    return 0;
}
