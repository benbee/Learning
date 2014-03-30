#include <iostream>

using namespace std;

class CDemo {
private:
    int n;
public:
    CDemo(int i = 0): n(i) { }
    CDemo & operator++();         // qianzhi
    CDemo operator++(int);      // houzhi
    operator int () { return n; }
    friend CDemo & operator--(CDemo &);
    friend CDemo operator--(CDemo &, int);
};

CDemo & CDemo::operator++ () {     // front
    n++;
    return *this;
}

CDemo CDemo::operator++ (int i) { // tail
    CDemo temp(*this);
    n++;
    return temp;
}

CDemo & CDemo::operator-- (CDemo & d) { // front
    d.n--;
    return d;
}

CDemo CDemo::operator-- (CDemo & d, int k) { // back
    CDemo temp(d);
    n--;
    return temp;
}

operator int () {return n;}

int main(int argc, char *argv[])
{
    CDemo d(5);
    cout << (d++) << ",";
    cout << d << ",";
    cout << (++d) << ",";
    cout << d << endl;
    cout << (d--) << ",";
    cout << (--d) << ",";
    cout << d << endl;
    return 0;
}
