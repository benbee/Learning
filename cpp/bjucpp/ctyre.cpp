#include <iostream>

using namespace std;

class CTyre {
private:
    int radius;
    int width;
public:
    CTyre(int r, int w): radius(r), width(w) { }
    CTyre() { cout << "CTyre contructor" << endl; }
    ~CTyre() { cout << "CTyre destructor" << endl;}
};

class CEngine {
public:
    CEngine() { cout << "CEngine constructor" << endl; }
    ~CEngine() { cout << "CEngine destructor" << endl; }
};

class CCar {
private:
    int price;
    CEngine engine;
    CTyre tyre;
public:
    CCar(int p, int tr, int tw);
    CCar() { cout << "CCar constructor" << endl; }
    ~CCar() { cout << "CCar destructor" << endl; }
};

CCar::CCar(int p, int tr, int w): price(p), tyre(tr, w) {

};

int main()
{
    //CCar car(20000, 17, 225);
    CCar car;
    return 0;
}
