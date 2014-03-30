#include <iostream>
#include <string.h>

using namespace std;

#define MAXLEN 100

class BigInt {
private:
    int len;
    char digits[MAXLEN];
public:
    BigInt(void);
    BigInt(int i);
    BigInt(const char *str);
    void printBigInt(void);
    BigInt operator+ (const BigInt & b);
    //BigInt operator= (char *num);
};

// BigInt BigInt::operator= (char *num) {
//     len = strlen(num);
//     for (int i = 0; i < len; i++) {
//         digits[i] = num[len - i - 1] + '0';
//     }
// }

BigInt BigInt::operator+ (const BigInt & b) {
    BigInt result;
    for (int i = 0; i < MAXLEN - 1; i++) {
        cout << result.digits[i] << endl;
    }
    for (int i = 0, c = 0; i <= MAXLEN; i++) {
        //cout << digits[i] - '0' << " + " << b.digits[i] - '0' << endl;
        int sum = digits[i] + b.digits[i] + c;
        result.digits[i] = sum % 10;
        c = sum / 10;
    }
    int j = 0;
    while (result.digits[j] != '\0')
        j++;
    result.len = 3;
    result.printBigInt();
    return result;
}

BigInt::BigInt(void) {
    memset(digits, 0, sizeof(digits));
    len = 0;
}

BigInt::BigInt(const char *s) {
    int i;

    for (i = 0; i < MAXLEN && s[i] != '\0'; i++) {
        digits[i] = s[strlen(s) - i - 1];
    }

    len = i;
}

BigInt::BigInt(const int integer) {
    int j = 0;
    int i = integer;
    while (i > 0) {
        digits[j++] = (i % 10) + '0';
        i /= 10;
    }
    digits[j] = '\0';
    len = j;
}

void BigInt::printBigInt()
{
    for (int i = len - 1; i >= 0; i--) {
        cout << digits[i];
    }
    cout << endl;
    //cout << "len: " << len << endl;
}

int main(int argc, char *argv[])
{
    char ch1[100], ch2[100];
    cin >> ch1;
    cin >> ch2;

    BigInt bi1(ch1), bi2(ch2);

    // bi1 = ch1;
    bi1.printBigInt();


    // bi2 = ch2;
    bi2.printBigInt();
    //bi2 = bi2 + bi1;
    bi1+bi2;
    //(bi2 + bi1).printBigInt();

    return 0;
}
