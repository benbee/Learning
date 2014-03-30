#include <stdio.h>

using namespace std;

#define MAXLEN 300;

class BigInt {
private:
    int len;
    char digits[MAXLEN];
public:
    BigInt(int i);
    BitInt(char *str);
};

BigInt::BigInt(int i) {
    len = 0;
    len = (char *)(i).length();

    for (int j = 0; j < len; j++) {
        digits[i] =
    }
}

ostream & ostream::operator<<(ostream & o, const BigInt bi)
{
    o << bi.digits;
    return o;
}
