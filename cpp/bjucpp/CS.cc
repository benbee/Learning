#include <iostream>

using namespace std;

class Complex
{
  public:
    double real, imag;
    Complex ( int i ) {
      cout << "IntConstructor called" << endl;
      real = i;
      imag = 0;
    };
    Complex(double r, double i) {
      real = r;
      imag = i;
    };

  private:
    /* data */
};

int main(int argc, char *argv[])
{
  Complex c1(7, 8);
  Complex c2 = 12;
  c1 = 10;
  cout << c1.real << "," << c1.imag << endl;
  return 0;
}
