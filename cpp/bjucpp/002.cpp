#include <iostream>

using namespace std;

class CRectangle {
public:
	int	w, h;
	
	void Init(int w_, int h_) {
		w = w_;
		h = h_;
	}

	int Area() {
		return w * h;
	}

	int Perimeter() {
		return 2 * (w + h);
	}
};

int main(int argc, char *argv[])
{
    int w, h;
	CRectangle r;				// r is a class
	cin >> w >> h;
	r.Init(w ,h);
	cout << r.Area() << endl << r.Perimeter()
		 << endl;
	
    return 0;
}
