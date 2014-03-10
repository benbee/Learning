#include <iostream>

using namespace std;

class CSsample {
	int x;
public:
	CSsample() {
		cout << "Constructor 1 Called" << endl;
	}
	CSsample(int n) {
		x = n;
		cout << "Constructor 2 Called" << endl;
	}
};

int main()
{
	CSsample array1[2];
	cout << "step1" << endl;

	CSsample array2[2] = {4, 5};
	cout << "step2" << endl;

	CSsample array3[2] = {3};
	cout << "step3" << endl;

	CSsample *array4 = new CSsample[](4);
	delete []array4;

	// cout << "step4" << endl;
	// CSsample *array5 = {new CSsample(1), new CSsample};
	// delete []array5;
		
	return 0;
}
